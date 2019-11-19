# gem5

#### gem5 install

* sudo apt install build-essential
* sudo apt install python python-dev
* sudo apt install scons m4 swig libboost-all-dev protobuf*
* sudo apt install zlib1g zlib1g-dev zlibc
* sudo apt install python-pip
* pip install pydot
* sudo apt install git cmake bison flex graphviz
* sudo apt install libgoogle-perftools-dev
* git clone https://gem5.googlesource.com/public/gem5 my_gem5

  


#### gem5 build for ARM ISAs

* scons build/ARM/gem5.opt -j4



#### gem5 run 

* ./build/ARM/gem5.opt configs/example/arm/starter_se.py --cpu="minor" "tests/test-progs/hello/bin/arm/linux/hello"

>run pre-complied program _hello_,
>parameters are declared in _starter_se.py_,
>exit status on _RESULTS_

* ./build/ARM/gem5.opt -d RESULTS configs/example/arm/starter_se.py
  --cpu="minor" "tests/test-progs/hello/bin/arm/linux/hello"

#### cross compilers

* sudo apt install gcc-arm-linux-gnueabihf
* sudo apt install g++-arm-linux-gnueabihf

> my code written in c: myprog.c

* arm-linux-gnueabihf-gcc --static myprog.c -o myprog_arm

#### cpu models & cpu clock to 1GHz

* ./build/ARM/gem5.opt -d RESULTS configs/example/se.py --cpu-type=MinorCPU --cpu-clock=1000000000 --caches -c tests/testprogs/hello/bin/arm/linux/hello





