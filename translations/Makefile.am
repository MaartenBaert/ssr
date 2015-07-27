if ENABLE_SSRPROGRAM

########## Qt translation system ##########

translationsdir = $(pkgdatadir)/translations

nodist_translations_DATA = \
	simplescreenrecorder_ar.qm \
	simplescreenrecorder_bg.qm \
	simplescreenrecorder_cs.qm \
	simplescreenrecorder_de.qm \
	simplescreenrecorder_el.qm \
	simplescreenrecorder_es.qm \
	simplescreenrecorder_he.qm \
	simplescreenrecorder_hu.qm \
	simplescreenrecorder_it.qm \
	simplescreenrecorder_nl.qm \
	simplescreenrecorder_pl.qm \
	simplescreenrecorder_pt_BR.qm \
	simplescreenrecorder_ru.qm \
	simplescreenrecorder_sv.qm \
	simplescreenrecorder_uk.qm \
	simplescreenrecorder_zh_CN.qm

EXTRA_DIST = \
	simplescreenrecorder_ar.ts \
	simplescreenrecorder_bg.ts \
	simplescreenrecorder_cs.ts \
	simplescreenrecorder_de.ts \
	simplescreenrecorder_el.ts \
	simplescreenrecorder_es.ts \
	simplescreenrecorder_he.ts \
	simplescreenrecorder_hu.ts \
	simplescreenrecorder_it.ts \
	simplescreenrecorder_nl.ts \
	simplescreenrecorder_pl.ts \
	simplescreenrecorder_pt_BR.ts \
	simplescreenrecorder_ru.ts \
	simplescreenrecorder_sv.ts \
	simplescreenrecorder_uk.ts \
	simplescreenrecorder_zh_CN.ts

simplescreenrecorder_ar.qm: $(srcdir)/simplescreenrecorder_ar.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_bg.qm: $(srcdir)/simplescreenrecorder_bg.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_cs.qm: $(srcdir)/simplescreenrecorder_cs.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_de.qm: $(srcdir)/simplescreenrecorder_de.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_el.qm: $(srcdir)/simplescreenrecorder_el.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_es.qm: $(srcdir)/simplescreenrecorder_es.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_he.qm: $(srcdir)/simplescreenrecorder_he.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_hu.qm: $(srcdir)/simplescreenrecorder_hu.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_it.qm: $(srcdir)/simplescreenrecorder_it.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_nl.qm: $(srcdir)/simplescreenrecorder_nl.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_pl.qm: $(srcdir)/simplescreenrecorder_pl.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_pt_BR.qm: $(srcdir)/simplescreenrecorder_pt_BR.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_ru.qm: $(srcdir)/simplescreenrecorder_ru.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_sv.qm: $(srcdir)/simplescreenrecorder_sv.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_uk.qm: $(srcdir)/simplescreenrecorder_uk.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_zh_CN.qm: $(srcdir)/simplescreenrecorder_zh_CN.ts
	$(LRELEASE) "$<" -qm "$@"

clean-translations-extra:
	rm -f simplescreenrecorder_*.qm

########## Extra targets ##########

clean-local: clean-translations-extra

.PHONY: clean-translations-extra

endif
