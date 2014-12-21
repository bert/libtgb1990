
ACLOCAL_AMFLAGS = `-I m4` 

SUBDIRS = \
	doc \
	src
	
libtgb1990docdir = ${prefix}/doc

libtgb1990doc_DATA = \
	ABOUT-NLS \
	AUTHORS \
	BUGS \
	ChangeLog \
	CONTRIBUTING \
	COPYING \
	INSTALL \
	ISSUES \
	LICENSE \
	MANIFEST \
	NEWS \
	README \
	TODO
	
EXTRA_DIST = $(libtgb1990doc_DATA)

# Copy all the spec files. Of cource, only one is actually used.
dist-hook:
	for specfile in *.spec; do \
		if test -f $$specfile; then \
			cp -p $$specfile $(distdir); \
		fi \
	done
	
## generate API documentation with doxygen
apidox:
	$(MAKE) apidox-am-@LIBTGB1990_HAS_DOXYGEN@

apidox-am-no:
apidox-am-yes:
	@echo "*** Creating API documentation main page"; \
	cd doc/doxygen; \
	doxygen libtgb1990.dox

.PHONY: apidox-am-yes apidox-am-no apidox

