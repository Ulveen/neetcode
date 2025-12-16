#include <iostream>

using namespace std;

class Solution {
private:
  bool isPalindrome(string &s, int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--])
        return false;
    }
    return true;
  }

public:
  string longestPalindrome(string s) {
    int windowSize = s.length();

    for (int i = windowSize; i > 0; i--) {
      for (int j = 0; j <= s.length() - i; j++) {
        if (isPalindrome(s, j, j + i - 1))
          return s.substr(j, i);
      }
    }

    return "";
  }
};

int main() {
  string s = "babad";
  string result = Solution().longestPalindrome(s);
  cout << result << endl;
}
