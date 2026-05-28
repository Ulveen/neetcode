#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        
        int result = 0;
        vector<int>& prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] == prev[0] || intervals[i][0] < prev[1]) {
                if (intervals[i][1] < prev[1]) prev = intervals[i];
                result++;
            }
            else {
                prev = intervals[i];
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> intervals = {
        {-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    int result = Solution().eraseOverlapIntervals(intervals);
    cout << "Result: " << result << endl;
}