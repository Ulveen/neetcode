#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<string>> result;
  bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
      if (s[l++] != s[r--])
        return false;
    }
    return true;
  }
  void backtrack(string s, int idx, vector<string> combination) {
    if (idx >= s.length()) {
      result.push_back(combination);
      return;
    }
    for (int i = 1; i <= s.length() - idx; i++) {
      string temp = s.substr(idx, i);
      if (isPalindrome(temp)) {
        combination.push_back(temp);
        backtrack(s, idx + i, combination);
        combination.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    result = {};
    backtrack(s, 0, {});
    return result;
  }
};

int main() {
  string s = "aab";
  vector<vector<string>> result = Solution().partition(s);

  for (auto arr : result) {
    for (string a : arr) {
      cout << a << " ";
    }
    cout << endl;
  }
}
