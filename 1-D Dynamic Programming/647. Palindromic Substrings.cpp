#include <iostream>

using namespace std;

class Solution {
private:
  int traverse(string &s, int start, int end) {
    int count = 0;
    while (start - count >= 0 && end + count < s.length() &&
           s[start - count] == s[end + count]) {
      count++;
    }
    return count;
  }

public:
  int countSubstrings(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
      int odd = traverse(s, i - 1, i + 1) + 1;
      int even = traverse(s, i, i + 1);

      result += odd + even;
    }
    return result;
  }
};

int main() {
  string s = "aaa";
  int result = Solution().countSubstrings(s);

  cout << result << endl;
}
