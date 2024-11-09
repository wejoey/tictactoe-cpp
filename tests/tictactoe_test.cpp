#include <gtest/gtest.h>

#include "../src/tictactoe.h"

TEST(TictactoeTest, GameOver) {
  TicTacToeCpp::TicTacToeGame game;
  EXPECT_FALSE(game.isGameOver());
}