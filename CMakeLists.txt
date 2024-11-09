cmake_minimum_required(VERSION 3.9)
project(tictactoe-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

# Create symlink in root IDE to pick it up
# https://stackoverflow.com/questions/59263015/cmake-how-to-change-compile-commands-json-output-location
if (PROJECT_IS_TOP_LEVEL AND UNIX)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()
