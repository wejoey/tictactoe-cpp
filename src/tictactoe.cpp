#include <array>
#include <iostream>
#include <string>

//enum STATE { X, O, EMPTY };

using TicTacToeBoard = std::array<std::array<char, 3>, 3>;

// struct Round {
//   STATE xo;
//   std::string toString() { return xo == EMPTY ? "" : xo == X ? "X" : "O"; }
// };

class TicTacToeGame {

public:
  TicTacToeGame(){
    for (auto& row : m_Board)
    {
      row[0] = ' ';
      row[1] = ' ';
      row[2] = ' ';
    }
  }

  void playTurn() {

    bool valid = false;
    while (!valid)
    {
      std::cout << "Play 'X': \n";
      unsigned int turn;
      std::cin >> turn;
      std::cout << "entered: " << turn << std::endl;

      if (turn > 0 && turn < 9){
        valid = true;
      }
      else{
        std::cout << "invalid\n";
      }
    }


  }

  void drawBoard() {
    for (const auto& row : m_Board)
    {
      std::cout << " " << row[0] << " | " << row[1] << " | " << row[2] << " \n";
    }
  }

  bool isGameOver() {
    if (false) {
      return true;
    }
    else{
      return false;
    }
  }

  void printHowToPlay() {
    std::cout << "Play your turn by entering number from 1 to 9 representing "
                 "the position to play.\n";
    std::cout << " 1 | 2 | 3 \n";
    std::cout << "---|---|---\n";
    std::cout << " 4 | 5 | 6 \n";
    std::cout << "---|---|---\n";
    std::cout << " 7 | 8 | 9 \n";
    std::cout << "\nPress the ENTER key to start the game.\n";
  }

  void printGameOver() {
    std::string printGameOver = "\n\nGame over!\n";

    if (m_Draw){
      printGameOver += "The game is a DRAW.\n";
    }
    else{
     printGameOver += "The winner is ...";
    }

    std::cout << printGameOver;
  }

private:
  TicTacToeBoard m_Board;
  bool m_End = false;
  bool m_Draw = false;
};

//=============================================================================

int main() {
  TicTacToeGame game;

  game.printHowToPlay();

  while (!game.isGameOver()) {
    game.playTurn();
    game.drawBoard();
  }

  game.printGameOver();
}
