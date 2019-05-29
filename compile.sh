#!/bin/bash

# to run in container
./gyp/gyp -f make -Duv_library=static_library --depth=. --generator-output=build
make -C build
