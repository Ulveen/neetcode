#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][0], right = intervals[0][1], idx = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > right)
            {
                intervals[idx][0] = left;
                intervals[idx++][1] = right;
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else
            {
                right = max(right, intervals[i][1]);
            }
        }

        intervals[idx] = { left, right };
        int popCount = intervals.size() - idx - 1;
        for (int i = 0; i < popCount; i++)
        {
            intervals.pop_back();
        }
        return intervals;
    }
};

int main()
{
    vector<vector<int>> intervals = {
        {1, 4}, {4, 5}};
    vector<vector<int>> result = Solution().merge(intervals);
    for (vector<int>& v : result)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}