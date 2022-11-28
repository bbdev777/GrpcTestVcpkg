# GrpcTestVcpkg
# Install vcpkg anf grpc

sudo apt update
sudo apt install -y zip unzip
sudo apt install -y build-essential pkg-config

wget -O vcpkg.tar.gz https://github.com/microsoft/vcpkg/archive/master.tar.gz
sudo mkdir /opt/vcpkg
sudo tar xf vcpkg.tar.gz --strip-components=1 -C /opt/vcpkg
sudo /opt/vcpkg/bootstrap-vcpkg.sh
sudo ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg
vcpkg version

sudo /opt/vcpkg integrate install
sudo /opt/vcpkg install grpc
