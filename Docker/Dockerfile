FROM ubuntu:20.04 AS build-temp

EXPOSE 80

ENV DEBIAN_FRONTEND="noninteractive"
ENV TZ="UTC"
ENV PATH="$PATH:/src/vcpkg/installed/x64-linux/tools/protobuf/"

RUN apt update \
	&& apt -y install \
		build-essential \
		cmake \
		curl \
		git \
		ninja-build \
		pkg-config \
		tar \
		unzip \
		zip \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /src/

####################################################################################################
# Vcpkg
####################################################################################################
RUN cd /src && git clone --no-checkout https://github.com/Microsoft/vcpkg && cd vcpkg && git checkout 3768cef9c204bb168c04b3ba7cb93b10a140a91d

RUN /src/vcpkg/bootstrap-vcpkg.sh
RUN /src/vcpkg/vcpkg install grpc

####################################################################################################
# Apps
####################################################################################################

#VOLUME ["/data"]

RUN mkdir -p /src/TestApp
RUN mkdir -p /build-dir

RUN --mount=type=bind,source=.,target=/src/TestApp \
    --mount=type=cache,target=/build-dir \
    cd /build-dir \
    && cmake -p -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_TOOLCHAIN_FILE=/src/vcpkg/scripts/buildsystems/vcpkg.cmake \
        /src/TestApp \
    && ninja clean \
    && ninja -j `nproc` && \
    cp ./GrpcTest.Server /GrpcTest.Server && \
    cp ./GrpcTest.Client /GrpcTest.Client

FROM ubuntu:20.04 AS release
COPY --from=build-temp /GrpcTest.Server /GrpcTest.Server
COPY --from=build-temp /GrpcTest.Client /GrpcTest.Client
