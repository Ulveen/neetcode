#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution
{
private:
    int evaluate(int first, int second, char op)
    {
        switch (op)
        {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '/':
            return first / second;
        case '*':
            return first * second;
        default:
            return 0;
        }
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (string token : tokens)
        {
            if (token.length() > 1 || isdigit(token[0]))
            {
                st.push(stoi(token));
                continue;
            }
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();
            int temp = evaluate(first, second, token[0]);
            st.push(temp);
        }

        return st.top();
    }
};

int main()
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result = Solution().evalRPN(tokens);
    cout << result;
}