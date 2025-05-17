#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
    public:
    string encode(vector<string>& strs) {
        string buffer = "";
        for (string s : strs) {
            string sub = "#" + to_string(s.length());
            buffer = s + sub + buffer;
        }
        return buffer;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int start = 0;
        int len = s.length();
        int prev_tag = 0;
        while(start < len) {
            int end = s.find("#", prev_tag);
            if (end == string::npos) {
                break;
            }
            int sub_len = end - start;
            int idx = 1;
            bool flag = false;
            while(end + idx < len) {
                if (!isdigit(s[end + idx])) {
                    flag = true;
                    break;
                }
                int check_len = stoi(s.substr(end + 1, idx));
                if (sub_len == check_len) {
                    break;
                }
                idx++;
            }
            if (flag) {
                prev_tag = end + 1;
                continue;
            }
            result.push_back(s.substr(start, sub_len));
            prev_tag = start = end + idx + 1;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<string> strs = {"we","say",":","yes","!@#$%^&*()"};
    string buffer = Solution().encode(strs);
    vector<string> decoded = Solution().decode(buffer);
    for (string s : decoded) {
        cout << s << ", ";
    }
}