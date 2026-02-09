#include <iostream>
#include <vector>

using namespace std;

struct Node {
  Node *nodes[26] = {nullptr};
  bool isEndOfWord = false;
  int idx = 0;
};

class Solution {
private:
  Node *root;
  vector<int> result;

  void addWord(int idx, string word) {
    Node *node = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!node->nodes[idx]) {
        node->nodes[idx] = new Node();
      }
      node = node->nodes[idx];
    }
    node->idx = idx;
    node->isEndOfWord = true;
  }

  void searchWord(Node *node, vector<vector<char>> &board, int y, int x) {
    if (y < 0 || x < 0 || y >= board.size() || x >= board[0].size() ||
        board[y][x] == '#') {
      return;
    }

    char c = board[y][x];
    int idx = c - 'a';

    Node *newNode = node->nodes[idx];
    if (!newNode) {
      return;
    }

    if (newNode->isEndOfWord) {
      if (newNode->idx != -1) {
        result.push_back(newNode->idx);
        newNode->idx = -1;
      }
    }

    board[y][x] = '#';

    searchWord(newNode, board, y - 1, x);
    searchWord(newNode, board, y + 1, x);
    searchWord(newNode, board, y, x + 1);
    searchWord(newNode, board, y, x - 1);

    board[y][x] = c;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    root = new Node();
    for (int i = 0; i < words.size(); i++) {
      addWord(i, words[i]);
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        searchWord(root, board, i, j);
      }
    }

    vector<string> mapped;
    for (int i : result) {
      mapped.push_back(words[i]);
    }

    return mapped;
  }
};

int main() {
  vector<vector<char>> board = {{'a'}};
  vector<string> words = {"a"};

  vector<string> result = Solution().findWords(board, words);
  for (string word : result) {
    cout << word << " ";
  }
  cout << endl;
}
