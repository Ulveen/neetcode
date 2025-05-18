#include<iostream>
#include<ctype.h>

using namespace std;

class Solution {
    public:
    bool isPalindrome(string s) {
        string a;
        for (char c : s) {
            if (isalpha(c) || isdigit(c)) {
                a += tolower(c);
            }
        }
        int l = 0, r = a.length() - 1;
        while (l < r) {
            if (a[l++] != a[r--]) return false;
        }
        return true;
    }
};

int main() {
    string s = "makloolkam";
    bool result = Solution().isPalindrome(s);
    printf("%s", result ? "true" : "false");
}