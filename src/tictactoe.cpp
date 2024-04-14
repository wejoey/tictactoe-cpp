#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <utility>
#include <variant>
namespace TicTacToeCpp {

struct TicTacToeGame {

  enum STATE : char { X = 'X', O = 'O', EMPTY = ' ' };
  using TicTacToeBoard = std::array<std::array<STATE, 3>, 3>;
  using Position = std::pair<unsigned int, unsigned int>;

  TicTacToeBoard m_Board{
      {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}}};
  bool m_End{false};
  bool m_Draw{false};

  void play() {

    printHowToPlay();

    while (!isGameOver()) {
      bool validTurn = false;
      while (!validTurn && !isGameOver()) {
        std::cout << "Play 'X': \n";
        unsigned int turn{0};
        std::cin >> turn;

        auto position = getPositionInput(turn);
        if (std::holds_alternative<Position>(position)) {
          m_Board[std::get<Position>(position).first]
                 [std::get<Position>(position).second] = X;
          validTurn = true;
        } else {
          std::cout << "*invalid entry, retry\n";
        }

        drawBoard();
      }

      validTurn = false;

      while (!validTurn && !isGameOver()) {
        std::cout << "Play 'O': \n";
        unsigned int turn{0};
        std::cin >> turn;
        auto position = getPositionInput(turn);
        if (std::holds_alternative<Position>(position)) {
          m_Board[std::get<Position>(position).first]
                 [std::get<Position>(position).second] = O;
          validTurn = true;
        } else {
          std::cout << "*invalid entry, retry\n";
        }
        drawBoard();
      }
    }
    printGameOver();
  }

  static Position getRowColPair(unsigned int input) {
    switch (input) {
    case 1:
      return std::move(std::make_pair(0, 0));
    case 2:
      return std::move(std::make_pair(0, 1));
    case 3:
      return std::move(std::make_pair(0, 2));
    case 4:
      return std::move(std::make_pair(1, 0));
    case 5:
      return std::move(std::make_pair(1, 1));
    case 6:
      return std::move(std::make_pair(1, 2));
    case 7:
      return std::move(std::make_pair(2, 0));
    case 8:
      return std::move(std::make_pair(2, 1));
    case 9:
    default:
      return std::move(std::make_pair(2, 2));
    }
  }

  std::variant<bool, Position> getPositionInput(unsigned int input) {
    if (input == 0){
      exit(0);
    }

    if (input > 9) {
      return false;
    }
    const auto position = getRowColPair(input);
    if (m_Board[position.first][position.second] != EMPTY) {
      return false;
    }
    return position;
  }

  void drawBoard() {
    static constexpr std::string_view BOARD_LINE{"-----------\n"};
    for (const auto &row : m_Board) {
      std::cout << BOARD_LINE << " " << row[0] << " | " << row[1] << " | "
                << row[2] << " \n";
    }
    std::cout << BOARD_LINE;
  }

  bool isGameOver() {
    for (int row = 0; row < 3; row++) {
      for (int col = 0; col < 3; col++) {
        if (m_Board[row][col] == EMPTY) {
          return false;
        }
      }
    }
    return true;
  }

  static void printHowToPlay() {
    std::cout << R"(
Play your turn by entering number from 1 to 9 representing the position to play.
 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9
Press '0' to quit the game.")";
  }

  void printGameOver() {
    std::string strGameOver{"\n\nGame over!\n"};

    if (m_Draw) {
      strGameOver += "The game is a DRAW.\n";
    } else {
      strGameOver += "The winner is ...";
    }

    std::cout << strGameOver;
  }

}; // struct

} // namespace TicTacToeCpp

//=============================================================================

int main() {
  TicTacToeCpp::TicTacToeGame game;
  game.play();
}