# tictactoe-cpp

A simple game to introduce my son to programming.

## CMake generate

```shell
mkdir debug
cmake -B debug -G Ninja -D CMAKE_BUILD_TYPE=Debug
```

## CMake build

```shell
cmake --build debug
```

## Test

```shell
ctest --test-dir debug
```

## run

`./debug/tictactoe`
