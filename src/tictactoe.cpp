#include <iostream>

void getInput() {}

void process() {}

void drawBoard() {
  std::cout << "3 | X |   | O \n";
  std::cout << "2 |   | X |   \n";
  std::cout << "1 |   |   | O \n";
  std::cout << "--------------\n";
  std::cout << "    a   b   c \n";
}
//======================================================================================
int main() {
  bool endOfTheGame = false;

  while (!endOfTheGame) {
    getInput();
    process();
    drawBoard();
    endOfTheGame = true;
  }
}
