# tictactoe-cpp

A simple game to introduce my son to programming.

## build

```shell
mkdir debug
cmake -B debug -G Ninja -D CMAKE_BUILD_TYPE=Debug
cmake --build debug
```

## run

`./debug/tictactoe`

## test

`./debug/tictactoe_test`
todo use `ctest`
