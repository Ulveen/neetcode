#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> temperatures)
    {
        int len = temperatures.size();
        
        vector<int> result (len);
        stack<int> st;

        for (int i = 0; i < len; i++)
        {
            int curr = temperatures[i];
            while (!st.empty() && temperatures[st.top()] < curr)
            {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            result[st.top()] = 0;
            st.pop();
        }
        return result;
    }
};

int main()
{
    vector<int> temperatures = {30, 60, 90};
    vector<int> result = Solution().dailyTemperatures(temperatures);
    for (int temp : result)
    {
        cout << temp << " ";
    }
}