#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> sols;

bool check(vector<string>& board, int row, int col) {
  int n = board.size();
  for (int i = 0; i < n; i++) {
    if (board[i][col] == 'Q') return false;  // checking if any queen already placed on same column previously
    // checking all diagonals-
    if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
    if (row - i >= 0 && col + i < n && board[row - i][col + i] == 'Q') return false;
    if (row + i < n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
    if (row + i < n && col + i < n && board[row + i][col + i] == 'Q') return false;
  }
  return true;
}
// Recursive solver - Tries all possible placement of queen for current row & recurses for next row
void solve(vector<string>& board, int row) {
  // base condition. When we reach here, a valid placement combination has been formed. So insert it into ans
  if (row == board.size()) {
    sols.push_back(board);
    return;
  }
  // Try placing a queen on each column for a given row. Explore next row by placing Q at each valid column for the current row
  for (int col = 0; col < (board.size()); col++)
    if (check(board, row, col)) {
      board[row][col] = 'Q';  // Queen placed on a valid cell
      solve(board, row + 1);  // exploring next row
      board[row][col] = '.';  // backtracking to get all possible solutions
    }
}

vector<vector<string>> solveNQueens(int n) {
  vector<string> board(n, string(n, '.'));  // creating an empty board
  solve(board, 0);
  return sols;
}

int main() {
  solveNQueens(8);
  for (int i = 0; i < 1; i++) {
    for (auto m : sols[i]) {
      cout << m << endl;
    }
    cout << endl;
    break;
  }
}