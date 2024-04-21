cmake_minimum_required(VERSION 3.9)

project(tictactoe-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(tictactoe src/tictactoe.cpp)
add_executable(tictactoe_test test/tictactoe_test.cpp)

target_link_libraries(
  tictactoe_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tictactoe_test)