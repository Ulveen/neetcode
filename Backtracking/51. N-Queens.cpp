#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<string>> result;
  vector<string> board;
  unordered_set<int> cols;
  unordered_set<int> diag1;
  unordered_set<int> diag2;

  void backtrack(int row, int n) {
    if (cols.size() == n) {
      result.push_back(board);
      return;
    }

    if (row >= n) {
      return;
    }

    for (int i = 0; i < n; i++) {
      int d1 = row + i;
      int d2 = row - i;

      if (diag1.find(d1) != diag1.end() || diag2.find(d2) != diag2.end() ||
          cols.find(i) != cols.end()) {
        continue;
      }

      cols.insert(i);
      diag1.insert(d1);
      diag2.insert(d2);

      board[row][i] = 'Q';
      backtrack(row + 1, n);
      board[row][i] = '.';

      cols.erase(i);
      diag1.erase(d1);
      diag2.erase(d2);
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    result = {};
    cols = {};
    diag1 = {};
    diag2 = {};

    string temp = string(n, '.');
    for (int i = 0; i < n; i++) {
      board.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
      backtrack(i, n);
    }

    return result;
  }
};

int main() {
  int n = 4;
  vector<vector<string>> result = Solution().solveNQueens(n);

  for (auto v : result) {
    for (string s : v) {
      cout << s << endl;
    }
    cout << endl << endl;
  }
}
