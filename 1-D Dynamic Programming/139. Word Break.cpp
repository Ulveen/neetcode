#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j]) {
          string sub = s.substr(j, i - j);
          if (dict.find(sub) != dict.end()) {
            dp[i] = true;
            break;
          }
        }
      }
    }

    return dp[n];
  }
};

int main() {
  string s = "applepenapple";
  vector<string> wordDict = {"apple", "pen"};

  bool result = Solution().wordBreak(s, wordDict);
  if (result) {
    cout << "True";
  } else {
    cout << "False";
  }
  puts("");
}
