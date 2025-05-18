#include<iostream>
#include<ctype.h>

using namespace std;

class Solution {
    public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (!isalnum(s[l])) {
                l++;
            }
            if (!isalnum(s[r])) {
                r--;
            }
            if (isalnum(s[l]) && isalnum(s[r])) {
                if (tolower(s[l++]) != tolower(s[r--])) return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "makloolkam";
    bool result = Solution().isPalindrome(s);
    printf("%s", result ? "true" : "false");
}