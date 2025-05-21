#include <iostream>
#include <vector>

using namespace std;

class Solution
{
vector<string> result;
private:
    void r(string curr, int open, int close) {
        if (open == 0 && close == 0) {
            this->result.push_back(curr);
            return;
        } 
        if (open > 0) r(curr + "(", open - 1, close);
        if (close > open) r(curr + ")", open, close - 1);
    }
public:
    vector<string> generateParenthesis(int n)
    {
        r("", n, n);
        return this->result;
    }
};

int main()
{
    int n = 3;
    vector<string> result = Solution().generateParenthesis(n);
    for (string s : result)
    {
        cout << s << endl;
    }
}