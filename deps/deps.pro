TEMPLATE = lib

sfmllib.commands += \
	echo "Building dependencies..."; \
	#
	# Test for binaries.
	#
	`type git >/dev/null 2>&1` || exit 1; \
	#
	# SFML
	#
	echo "Building SFML..."; \
	#
	# Checkout the SFML git repository if it hasn't been yet.
	#
	cd SFML; \
	#
	# Build SFML if necessary.
	#
	test ! -d build \
		&& mkdir build \
		&& cd build \
		&& cmake
		
win32 {
	sfmllib.commands += -G "'MSYS Makefiles'"
}

sfmllib.commands += -DBUILD_SHARED_LIBS=off .. \
		&& make \
		&& cd .. \
	cd ../..; \
	echo "Done building SFML.";
	
sfmllib.target = s

QMAKE_EXTRA_TARGETS += sfmllib

PRE_TARGETDEPS += s

win32 {
	debug {
		QMAKE_POST_LINK = rm -f debug/libdeps*
	}
	else {
		QMAKE_POST_LINK = rm -f release/libdeps*
	}
}
else {
	QMAKE_POST_LINK = rm -f libdeps*
}
