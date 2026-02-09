#include <cstdio>
class Solution {
public:
  long long climbStairs(int n) {
    if (n <= 2) {
      return n;
    }
    long long a = 1;
    long long b = 2;

    for (int i = 1; i < n; i++) {
      long long temp = a + b;
      a = b;
      b = temp;
    }

    return a;
  }
};

int main() {
  int n = 45;
  long long result = Solution().climbStairs(n);

  printf("%lld\n", result);
}
