#include <iostream>
#include <vector>

using namespace std;

struct Node {
  Node *nodes[26] = {nullptr};
  bool isEndOfWord = false;
};

class Trie {
private:
  Node *root;

public:
  Trie() { this->root = new Node(); }

  void insert(string word) {
    Node *curr = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!curr->nodes[idx]) {
        curr->nodes[idx] = new Node();
      }
      curr = curr->nodes[idx];
    }
    curr->isEndOfWord = true;
  }

  bool search(string word) {
    Node *curr = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!curr->nodes[idx]) {
        return false;
      }
      curr = curr->nodes[idx];
    }
    return curr->isEndOfWord;
  }

  bool startsWith(string prefix) {
    Node *curr = root;
    for (char c : prefix) {
      int idx = c - 'a';
      if (!curr->nodes[idx]) {
        return false;
      }
      curr = curr->nodes[idx];
    }
    return true;
  }
};

int main() {
  vector<string> input = {"Trie",       "insert", "search", "search",
                          "startsWith", "insert", "search"};
  vector<vector<string>> params = {{},      {"apple"}, {"apple"}, {"app"},
                                   {"app"}, {"app"},   {"app"}};

  Trie trie;

  for (int i = 0; i < input.size(); i++) {
    string op = input[i];
    vector<string> param = params[i];
    if (op == "Trie") {
      trie = Trie();
    } else if (op == "insert") {
      trie.insert(param[0]);
    } else {
      bool result;
      if (op == "search") {
        result = trie.search(param[0]);
      } else if (op == "startsWith") {
        result = trie.startsWith(param[0]);
      }
      if (result) {
        cout << "True" << endl;
      } else {
        cout << "False" << endl;
      }
    }
  }
}
