#include <iostream>
#include <vector>

using namespace std;

struct Node {
  Node *nodes[26] = {nullptr};
  bool isEndOfWord = false;
};

class WordDictionary {
private:
  Node *root;

  bool iter(Node *node, string &word, int idx) {
    if (!node) {
      return false;
    }
    if (idx >= word.length()) {
      if (node->isEndOfWord) {
        return true;
      }
      return false;
    }
    if (word[idx] == '.') {
      for (int i = 0; i < 26; i++) {
        bool flag = iter(node->nodes[i], word, idx + 1);
        if (flag) {
          return true;
        }
      }
      return false;
    }
    return iter(node->nodes[word[idx] - 'a'], word, idx + 1);
  }

public:
  WordDictionary() { root = new Node(); }

  void addWord(string word) {
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

  bool search(string word) { return iter(root, word, 0); }
};

int main() {
  vector<string> input = {"WordDictionary", "addWord", "addWord",
                          "addWord",        "search",  "search"};
  vector<vector<string>> params = {
      {}, {"environment"}, {"envelope"}, {"encounter"}, {"en.."}, {"e..r"}};

  WordDictionary wd;

  for (int i = 0; i < input.size(); i++) {
    string op = input[i];
    vector<string> param = params[i];

    if (op == "WordDictionary") {
      wd = WordDictionary();
    } else if (op == "addWord") {
      wd.addWord(param[0]);
    } else if (op == "search") {
      bool result = wd.search(param[0]);
      if (result) {
        cout << "True" << endl;
      } else {
        cout << "False" << endl;
      }
    }
  }
}
