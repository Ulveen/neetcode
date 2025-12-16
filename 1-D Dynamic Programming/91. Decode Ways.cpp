#include <iostream>

using namespace std;

class Solution {
private:
  bool isValidSingle(char c) { return c > '0' && c <= '9'; }

  bool isValidDouble(string &s, int idx) {
    if (s[idx - 1] != '1' && s[idx - 1] != '2') {
      return false;
    }
    if (s[idx - 1] != '1' && s[idx] > '6') {
      return false;
    }
    return true;
  }

public:
  int numDecodings(string s) {
    if (s.empty() || !isValidSingle(s[0]))
      return 0;

    if (s.length() == 1)
      return 1;

    if (!isValidSingle(s[1]) && !isValidDouble(s, 1)) {
      return 0;
    }

    int dp[s.length()];
    dp[0] = 1;

    if (!isValidSingle(s[1]) || !isValidDouble(s, 1)) {
      dp[1] = 1;
    } else {
      dp[1] = 2;
    }

    for (int i = 2; i < s.length(); i++) {
      dp[i] = (isValidSingle(s[i]) ? dp[i - 1] : 0) +
              (isValidDouble(s, i) ? dp[i - 2] : 0);
    }

    return dp[s.length() - 1];
  }
};

int main() {
  string s = "26";
  int result = Solution().numDecodings(s);
  cout << result << endl;
}
