#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        stack<double> st;
        int fleets = 1, n = position.size();

        vector<pair<int, int>> comb(n);
        for (int i = 0; i < n; i++)
        {
            comb[i] = {position[i], speed[i]};
        }
        sort(comb.begin(), comb.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });

        for (int i = n - 1; i >= 0; i--)
        {
            st.push((double)(target - comb[i].first) / comb[i].second);
        }

        double prevFleet = st.top();

        while (!st.empty())
        {
            double curr = st.top();
            st.pop();
            if (curr > prevFleet)
            {
                fleets++;
                prevFleet = curr;
                continue;
            }
            prevFleet = max(curr, prevFleet);
        }

        return fleets;
    }
};

int main()
{
    int target = 10;
    vector<int> position = {0, 4, 2};
    vector<int> speed = {2, 1, 3};
    int result = Solution().carFleet(target, position, speed);
    cout << result;
}