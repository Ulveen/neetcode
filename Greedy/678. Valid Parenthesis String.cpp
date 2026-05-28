#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> a, b;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == '(') a.push(i);
            else if (c == '*') b.push(i);
            else if (!a.empty()) a.pop();
            else if (!b.empty()) b.pop();
            else return false;
        }
        while (!a.empty() && !b.empty() && b.top() > a.top())
        {
            b.pop();
            a.pop();
        }
        return a.empty();
    }
};

// **((
// **())
// ((*))*

int main()
{
    string s = "(((*)";
    bool result = Solution().checkValidString(s);
    printf("\nResult: %s\n", result ? "True" : "False");
}