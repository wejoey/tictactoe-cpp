include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(tictactoe_test tictactoe_test.cpp ../src/tictactoe.cpp)

#target_link_libraries(runUnitTests project1_lib)
target_link_libraries(
  tictactoe_test
  GTest::gtest_main
)

# define tests
add_test(
  NAME tictactoe_test
  COMMAND $<TARGET_FILE:tictactoe_test>
  )

include(GoogleTest)
gtest_discover_tests(tictactoe_test)
