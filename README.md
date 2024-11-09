![workflow-status](https://github.com/wejoey/tictactoe-cpp/actions/workflows/cmake-build-and-test.yml/badge.svg)

# tictactoe-cpp

A simple game to introduce my son to programming.

## CMake generate

```shell
mkdir build
cmake -B build -G Ninja -D CMAKE_BUILD_TYPE=Debug
```

## CMake build

```shell
cmake --build build
```

## Test

```shell
ctest --test-dir build
```

## run

`./build/tictactoe`
