#include "tictactoe.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <variant>

namespace TicTacToeCpp {

void TicTacToeGame::play() {

  resetGame();
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

void TicTacToeGame::resetGame() {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      m_Board[row][col] = EMPTY;
    }
  }
  m_Winner = EMPTY;
}

TicTacToeGame::Position TicTacToeGame::getRowColPair(unsigned int input) {
  switch (input) {
  case 7:
    return std::move(std::make_pair(0, 0));
  case 8:
    return std::move(std::make_pair(0, 1));
  case 9:
    return std::move(std::make_pair(0, 2));
  case 4:
    return std::move(std::make_pair(1, 0));
  case 5:
    return std::move(std::make_pair(1, 1));
  case 6:
    return std::move(std::make_pair(1, 2));
  case 1:
    return std::move(std::make_pair(2, 0));
  case 2:
    return std::move(std::make_pair(2, 1));
  case 3:
  default:
    return std::move(std::make_pair(2, 2));
  }
}

std::variant<bool, TicTacToeGame::Position>
TicTacToeGame::getPositionInput(unsigned int input) {
  if (input == 0) {
    exit(0);
  }

  if (input > 9) {
    return false;
  }
  const auto position = getRowColPair(input);
  if (m_Board[position.first][position.second] != TicTacToeGame::EMPTY) {
    return false;
  }
  return position;
}

void TicTacToeGame::drawBoard() {
  static constexpr std::string_view BOARD_LINE{"-----------\n"};
  for (const auto &row : m_Board) {
    std::cout << BOARD_LINE << " " << row[0] << " | " << row[1] << " | "
              << row[2] << " \n";
  }
  std::cout << BOARD_LINE;
}

bool TicTacToeGame::isGameOver() { return isGameOverMethod1(); }

// The hard way
bool TicTacToeGame::isGameOverMethod1() {
  if (m_Board[0][0] == STATE::X && m_Board[1][1] == STATE::X &&
      m_Board[2][2] == STATE::X) {
    m_Winner = X;
    return true;
  }
  if (m_Board[0][0] == STATE::O && m_Board[1][1] == STATE::O &&
      m_Board[2][2] == STATE::O) {
    m_Winner = O;
    return true;
  }
  if (m_Board[0][2] == STATE::X && m_Board[1][1] == STATE::X &&
      m_Board[2][0] == STATE::X) {
    m_Winner = X;
    return true;
  }
  if (m_Board[0][2] == STATE::O && m_Board[1][1] == STATE::O &&
      m_Board[2][0] == STATE::O) {
    m_Winner = O;
    return true;
  }
  if (m_Board[0][0] == STATE::X && m_Board[1][0] == STATE::X &&
      m_Board[2][0] == STATE::X) {
    m_Winner = X;
    return true;
  }
  if (m_Board[0][0] == STATE::O && m_Board[1][0] == STATE::O &&
      m_Board[2][0] == STATE::O) {
    m_Winner = O;
    return true;
  }
  if (m_Board[0][1] == STATE::X && m_Board[1][1] == STATE::X &&
      m_Board[2][1] == STATE::X) {
    m_Winner = X;
    return true;
  }
  if (m_Board[0][1] == STATE::O && m_Board[1][1] == STATE::O &&
      m_Board[2][1] == STATE::O) {
    m_Winner = O;
    return true;
  }
  if (m_Board[0][2] == STATE::X && m_Board[1][2] == STATE::X &&
      m_Board[2][2] == STATE::X) {
    m_Winner = X;
    return true;
  }
  if (m_Board[0][2] == STATE::O && m_Board[1][2] == STATE::O &&
      m_Board[2][2] == STATE::O) {
    m_Winner = O;
    return true;
  }
  for (int row = 0; row < 3; row++) {
    if (std::all_of(m_Board[row].cbegin(), m_Board[row].cend(),
                    [](int i) { return i == X; })) {
      m_Winner = X;
      return true;
    }
    if (std::all_of(m_Board[row].cbegin(), m_Board[row].cend(),
                    [](int i) { return i == O; })) {
      m_Winner = O;
      return true;
    }
  }
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (m_Board[row][col] == EMPTY) {
        return false;
      }
    }
  }
  return true;
}

void TicTacToeGame::printHowToPlay() {
  std::cout << R"(
Play your turn by entering number from 1 to 9 representing the position to play.
 7 | 8 | 9
---|---|---
 4 | 5 | 6
---|---|---
 1 | 2 | 3
Press '0' to quit the game.")";
}

void TicTacToeGame::printGameOver() {
  std::stringstream sstrGameOver{"\n\nGame over!\n"};

  if (m_Winner == EMPTY) {
    sstrGameOver << "The game is a DRAW.\n";
  } else {
    sstrGameOver << "The winner is ..." << m_Winner << std::endl;
  }

  std::cout << sstrGameOver.str();
}

} // namespace TicTacToeCpp
