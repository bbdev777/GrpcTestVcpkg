#!/bin/bash

set -e

VERSION="1.0.5"

export DOCKER_BUILDKIT=1
docker build --progress=plain -t 10.74.33.15:5000/test.application:"${VERSION}" -f ./Docker/Dockerfile .
docker push 10.74.33.15:5000/test.application:"${VERSION}"
