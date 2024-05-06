#include <iostream>
// ━┃┏┓┛┗

using std::cout, std::cin, std::string;

static inline bool check_for_rows(const int board[3][3]);
static inline bool check_for_col(const int board[3][3]);
static inline bool is_solved(const int board[3][3]);
static inline bool check_for_diag(const int board[3][3]);

int main() {
  int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  bool turn = false;
  int peice_loc;
  string buffer;

  while (!is_solved(board)) {
    if (turn) {
      cout << "Where does player 2 want to place there peice (format: <int "
              "1..=3><int 1..=3>)? ";
      cin >> buffer;
      peice_loc = atoi(buffer.c_str());
    } else {
      cout << "Where does player 1 want to place there peice (format: <int "
              "1..=3><int 1..=3>)? ";
      cin >> buffer;
      peice_loc = atoi(buffer.c_str());
    }
  }
}

static inline bool is_solved(const int board[3][3]) {
  return check_for_rows(board) || check_for_col(board) || check_for_diag(board);
}

static inline bool check_for_rows(const int board[3][3]) {
  return ((board[0][0] == board[0][1]) == board[0][2]) ||
         ((board[1][0] == board[1][1]) == board[1][2]) ||
         ((board[2][0] == board[2][1]) == board[2][2]);
}

static inline bool check_for_col(const int board[3][3]) {
  return ((board[0][0] == board[1][0]) == board[2][0]) ||
         ((board[0][1] == board[1][1]) == board[2][1]) ||
         ((board[0][2] == board[1][2]) == board[2][2]);
}

static inline bool check_for_diag(const int board[3][3]) {
  return ((board[0][0] == board[1][1]) == board[2][2]) ||
         ((board[0][2] == board[1][1]) == board[2][0]);
}

bool verify_input(int input) {
  return (input % 10) <= 3 && (input % 10) >= 1 && (input / 10) <= 3 &&
         (input / 10) >= 1;
}

int get(int board[3][3], int idx) {
	return board[idx%10][idx/10];
}
