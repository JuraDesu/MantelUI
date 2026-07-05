#/bin/bash

mkdir build

cd build

echo $1

if [ $1 == "--clear" ]; then
    rm -rf *
    cmake ..
fi

make
cd ..
./MantelUITest
