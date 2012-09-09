
# Simple Makefile forwarding to the build directory.

.PHONY: all gen-cmake

# Suppress the output of the forwarding of commands.
${VERBOSE}.SILENT:

all:
	make -C build $@

%:
	make -C build $@

gen-cmake:
	rm -rf build; mkdir build
	cd build; cmake ..; cd ..
