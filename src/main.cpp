#include "tictactoe.h"

#include <iostream>

int main() {
  TicTacToeCpp::TicTacToeGame game;

  bool playAgain{true};
  while (playAgain) {
    game.play();

    std::cout << "Play again ? [y/n]: ";
    unsigned char again{0};
    std::cin >> again;

    playAgain = !std::cin.fail() && again == 'y';
  }
}