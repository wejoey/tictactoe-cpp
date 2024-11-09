cmake_minimum_required(VERSION 3.9)

project(tictactoe-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# main code
add_executable(tictactoe src/tictactoe.cpp)

# tests
add_executable(tictactoe_test test/tictactoe_test.cpp)

target_link_libraries(
  tictactoe_test
  GTest::gtest_main
)

# enable testing functionality
enable_testing()

# define tests
add_test(
  NAME tictactoe_test
  COMMAND $<TARGET_FILE:tictactoe_test>
  )

include(GoogleTest)
gtest_discover_tests(tictactoe_test)

# Create symlink in root IDE to pick it up
# https://stackoverflow.com/questions/59263015/cmake-how-to-change-compile-commands-json-output-location
if (PROJECT_IS_TOP_LEVEL AND UNIX)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()
