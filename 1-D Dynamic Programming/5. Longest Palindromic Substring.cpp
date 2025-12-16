#include <iostream>

using namespace std;

class Solution {
private:
  int traverse(string &s, int start, int end) {
    while (start >= 0 && end < s.length() && s[start] == s[end]) {
      start--;
      end++;
    }
    return end - start - 1;
  }

public:
  string longestPalindrome(string s) {
    int start = 0;
    int len = 1;

    for (int i = 0; i < s.length(); i++) {
      int odd = traverse(s, i - 1, i + 1);
      int even = traverse(s, i, i + 1);

      int candidateLen = max(odd, even);
      if (candidateLen > len) {
        len = candidateLen;
        start = i - (len - 1) / 2;
      }
    }
    return s.substr(start, len);
  }
};

int main() {
  string s = "bb";
  string result = Solution().longestPalindrome(s);
  cout << result << endl;
}
