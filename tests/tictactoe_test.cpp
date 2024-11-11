#include <gtest/gtest.h>

#include "../src/tictactoe.h"

TEST(TictactoeTest, TestThatNotGameOverAtStartup) {
  TicTacToeCpp::TicTacToeGame game;
}

TEST(TictactoeTest, TestThatNotGameOverAfterResetGame) {
  TicTacToeCpp::TicTacToeGame game;
  game.resetGame();
  EXPECT_FALSE(game.isGameOver());
}
