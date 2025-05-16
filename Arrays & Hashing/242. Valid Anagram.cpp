#include<iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.length();
        if (len != t.length()) {
            return false;
        }
        int a[26] = {0}, b[26] = {0};
        for(int i = 0; i < len; i++) {
            a[s[i] - 'a']++;
            b[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";

    bool result = Solution().isAnagram(s, t);
    printf("%s", result ? "true" : "false");
}