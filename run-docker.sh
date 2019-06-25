#!/bin/bash

docker build -t libuv-stripped .
docker run -m 16m -t libuv-stripped /bin/bash -c "./run-local.sh"
