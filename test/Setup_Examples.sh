#!/bin/bash
git clone https://github.com/GOMC-WSU/GOMC_Examples.git
mkdir integration

mkdir integration/new_cpu
cp -frd GOMC_Examples integration/new_cpu

mkdir integration/ref_cpu
cp -frd GOMC_Examples integration/ref_cpu

mkdir integration/new_gpu
cp -frd GOMC_Examples integration/new_gpu

mkdir integration/ref_gpu
cp -frd GOMC_Examples integration/ref_gpu

cd ..

startingBranch=$(git symbolic-ref HEAD | sed -e 's,.*/\(.*\),\1,')
echo "Building $startingBranch binaries"

./metamake.sh -g
mkdir -p test/new_binaries
cp -frdp ./bin/* test/new_binaries

echo "$startingBranch"
if [ "$startingBranch" == "development" ]; then
	echo "I am on development; checking out main"
	git checkout main
else
	echo "I am on $startingBranch; checking out development"
	git checkout development
fi

rm -frd bin
refBranch=$(git symbolic-ref HEAD | sed -e 's,.*/\(.*\),\1,')
echo "Building $refBranch binaries"
./metamake.sh -g
mkdir -p test/ref_binaries
cp -frd ./bin/* test/ref_binaries
cd test
git checkout "$startingBranch"