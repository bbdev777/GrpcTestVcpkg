# GrpcTestVcpkg

Install vcpkg anf grpc

sudo apt update<br>
sudo apt install -y zip unzip<br>
sudo apt install -y build-essential pkg-config<br>
wget -O vcpkg.tar.gz https://github.com/microsoft/vcpkg/archive/master.tar.gz<br>
sudo mkdir /opt/vcpkg<br>
sudo tar xf vcpkg.tar.gz --strip-components=1 -C /opt/vcpkg<br>
sudo /opt/vcpkg/bootstrap-vcpkg.sh<br>
sudo ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg<br>
vcpkg version<br>

sudo /opt/vcpkg integrate install<br>
sudo /opt/vcpkg install grpc<br>
