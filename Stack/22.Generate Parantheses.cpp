#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void r(vector<string>& result, string curr, int open, int close) {
        if (open == 0 && close == 0) {
            result.push_back(curr);
            return;
        } 
        if (open > 0) r(result, curr + "(", open - 1, close);
        if (close > open) r(result, curr + ")", open, close - 1);
    }
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        r(result, "", n, n);
        return result;
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