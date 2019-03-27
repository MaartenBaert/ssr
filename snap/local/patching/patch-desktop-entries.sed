# This sed script patches the desktop entries of the snapped
# application.
#
# Documentation:
#
# * GNU Sed Manual
#   https://www.gnu.org/software/sed/manual
#     * `sed` script overview - `sed` scripts
#     * `sed` commands summary - `sed` scripts
#     * The `s` Command - `sed` scripts
#     * Overview of basic regular expression syntax - Regular
#       Expressions: selecting text
#     * Back-references and Subexpressions - Regular Expressions:
#       selecting text

## Append '(Snap)' to the application name to make it
## distinguishable with the other same application using different
## software distribution technologies
##
## FIXME: The appended string is not localizable, the proper way to
##        implement this is to probably use a new X-Snappy-Name keys
##        with localestring format to let the translators fill in
##        additional localized string and use these values to replace
##        the Name keys here.
s/^\(Name\(\[.\+\]\)\?=.*\)$/\1 (Snap)/g

## Fix-up application icon lookup
s|^Icon=.*|Icon=\${SNAP}/meta/gui/icon.svg|
