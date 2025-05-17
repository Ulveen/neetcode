#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
    public:
    string encode(vector<string>& strs) {
        string buffer;
        for (const string& s : strs) {
            buffer += s + '#' + to_string(s.size());
        }
        return buffer;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<string> result;
        int prev_hash = s.size();
        while (true) {
            size_t hash = s.rfind('#', prev_hash);
            if (hash == string::npos) break;
            int sub_len = stoi(s.substr(hash + 1, prev_hash - hash));
            int begin = hash - sub_len;
            result.push_back(s.substr(begin, sub_len));
            if (begin <= 0) break;
            prev_hash = begin - 1;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<string> strs = {"#","##"};
    string buffer = Solution().encode(strs);
    vector<string> decoded = Solution().decode(buffer);
    for (string s : decoded) {
        cout << s << ", ";
    }
}