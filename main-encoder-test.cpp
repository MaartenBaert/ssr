#include "StdAfx.h"
#include "MainWindow.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"

#include "YUVConverter.h"

template<typename T>
inline T clamp(T minval, T maxval, T x) {
	if(x <= minval) return minval;
	if(x >= maxval) return maxval;
	return x;
}

inline uint32_t rgb(double r, double g, double b) {
	uint32_t rr = clamp(0.0, 1.0, r) * 255.0 + 0.5;
	uint32_t gg = clamp(0.0, 1.0, g) * 255.0 + 0.5;
	uint32_t bb = clamp(0.0, 1.0, b) * 255.0 + 0.5;
	return (rr << 16) | (gg << 8) | bb;
}

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	Q_UNUSED(app);
	/*MainWindow window;
	window.show();
	return app.exec();*/

	Logger logger;
	unsigned int width = 640, height = 480, framerate = 30, samplerate = 44100;

	logger.Log("Starting ...");

	Muxer muxer(&logger, "/home/maarten/Videos/test-ssr-v2.mp4");
	VideoEncoder venc(&logger, &muxer, width, height, framerate);
	AudioEncoder aenc(&logger, &muxer, samplerate);
	muxer.Start();

	YUVConverter yuv_converter(&logger);

	logger.Log("Generating video ...");
	std::vector<uint32_t> pixels(width * height);
	for(unsigned int i = 0; i < framerate * 4; ++i) {

		double t = (double)(i) / (double)(framerate) * 0.5;
		double circle_x = (double)(width) / 2.0, circle_y = (double)(height) / 2.0, circle_r = 80.0;
		circle_x += 140.0 * cos(t * 2.0 * M_PI);
		circle_y += 140.0 * sin(t * 2.0 * M_PI);
		for(unsigned int y = 0; y < height; ++y) {
			for(unsigned int x = 0; x < width; ++x) {
				double dist = hypot((double)(x) - circle_x, (double)(y) - circle_y);
				double val = clamp(0.0, 1.0, (circle_r - dist) / 20.0);
				double angle = atan2((double)(y) - circle_y, (double)(x) - circle_x);
				pixels[x + y * width] = rgb(val * (0.5 + 0.5 * sin(angle * 2.0 + t * 2.0 * M_PI)), val * (0.5 + 0.5 * cos(angle * 2.0 + t * 2.0 * M_PI)), val * 0.5);
			}
		}

		int l1 = grow_align16(width);
		int l2 = grow_align16(width / 2);
		int s1 = grow_align16(l1 * height);
		int s2 = grow_align16(l2 * height / 2);
		std::unique_ptr<AVFrameWrapper> frame(new AVFrameWrapper(s1 + 2 * s2));
		frame->data[1] = frame->data[0] + s1;
		frame->data[2] = frame->data[1] + s2;
		frame->linesize[0] = l1;
		frame->linesize[1] = l2;
		frame->linesize[2] = l2;
		frame->pts = i * 1000000 / framerate;
		yuv_converter.Convert(width, height, (uint8_t*)(pixels.data()), width * 4, frame->data, frame->linesize);
		venc.AddFrame(std::move(frame));

	}
	venc.Finish();

	logger.Log("Generating audio ...");
	unsigned int fs = aenc.GetRequiredFrameSize(), n = samplerate / fs * 4;
	double phase = 0.0, phase2 = 0.0;
	for(unsigned int i = 0; i < n; ++i) {

		std::unique_ptr<AVFrameWrapper> frame(new AVFrameWrapper(4 * fs));
		frame->linesize[0] = 4 * fs;
		frame->nb_samples = fs;

		for(unsigned int x = 0; x < fs; ++x) {
			phase += 2.0 * M_PI * 440.0 / (double)(samplerate);
			phase2 += 2.0 * M_PI * 0.5 / (double)(samplerate);
			double a = sin(phase);
			if(a > 0) a -= 0.3;
			else a += 0.3;
			int16_t left = round(a * (0.5 - 0.5 * cos(phase2)) * 30000.0);
			int16_t right = round(a * (0.5 + 0.5 * cos(phase2)) * 30000.0);
			((int16_t*)(frame->data[0]))[2 * x + 0] = left;
			((int16_t*)(frame->data[0]))[2 * x + 1] = right;
		}

		aenc.AddFrame(std::move(frame));

	}
	aenc.Finish();

	logger.Log("Stopping ...");
	while(!muxer.IsDone()) {
		usleep(10000);
	}
	logger.Log("Done!");

	return 0;
}

