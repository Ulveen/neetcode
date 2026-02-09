#include <iostream>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    if (s.empty())
      return 0;
    if (s[0] == '0')
      return 0;

    int dp[s.length() + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i < s.length(); i++) {
      dp[i] = 0;

      if (s[i] != '0') {
        dp[i] += dp[i - 1];
      }
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
        dp[i] += dp[i - 2];
      }
    }

    return dp[s.length() - 1];
  }
};

int main() {
  string s = "26";
  int result = Solution().numDecodings(s);
  cout << result << endl;
}
