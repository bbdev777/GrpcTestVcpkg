### Install vcpkg and grpc
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


### How to build
Go to /build folder run
run_cmake.sh


### How to run

The application converts number to string via grpc.

Open a console, go to /build folder and run<br>
GrpcTest.Server<br>

Output is:<br>
TestGrpcServer v1.0<br>

Open another console, go to /build folder and run<br>
GrpcTest.Client<br>

Output is:<br>
TestGrpcClient v1.0<br>
Source number 12345<br>
Result string 12345<br>


