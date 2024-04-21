#include <array>
#include <variant>

namespace TicTacToeCpp {

struct TicTacToeGame {
  enum STATE : char { X = 'X', O = 'O', EMPTY = ' ' };
  using TicTacToeBoard = std::array<std::array<STATE, 3>, 3>;
  using Position = std::pair<unsigned int, unsigned int>;

  TicTacToeBoard m_Board{
      {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}}};
  STATE m_Winner{EMPTY};

  void play();
  void resetGame();
  static Position getRowColPair(unsigned int input);
  std::variant<bool, Position> getPositionInput(unsigned int input);
  void drawBoard();
  bool isGameOver();
  bool isGameOverMethod1();
  static void printHowToPlay();
  void printGameOver();
}; // struct

} // namespace TicTacToeCpp
