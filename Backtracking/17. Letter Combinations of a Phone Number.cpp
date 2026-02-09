#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> mapping = {"abc", "def",  "ghi", "jkl",
                            "mno", "pqrs", "tuv", "wxyz"};
  vector<string> result;
  void backtrack(string digits, string combination, int idx) {
    if (idx >= digits.length()) {
      result.push_back(combination);
      return;
    }
    int curr = digits[idx] - '2';
    for (auto c : mapping[curr]) {
      combination.push_back(c);
      backtrack(digits, combination, idx + 1);
      combination.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    result = {};
    if (digits.empty())
      return result;
    backtrack(digits, "", 0);
    return result;
  }
};

int main() {
  string digits = "23";
  vector<string> result = Solution().letterCombinations(digits);

  for (auto s : result) {
    cout << s << " ";
  }
  cout << endl;
}
