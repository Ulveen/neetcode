#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
    public:
    bool isValid(string s) {
        stack<char> st;
        string leading = "([{", trailing = ")]}";
        for (char a: s) {
            if (leading.find(a) != string::npos) {
                st.push(a);
            }
            else if (trailing.find(a) != string::npos) {
                if (st.empty() || leading.find(st.top()) != trailing.find(a)) {
                    return false;
                }
                st.pop();
            }
            else {
                return false;
            }
        }
        return st.empty();
    }  
};

int main() {
    string s = "()";
    bool result = Solution().isValid(s);
    printf("%s", result ? "true" : "false");
}