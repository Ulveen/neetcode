#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        vector<pair<int, int>> qs;
        for (int i = 0; i < queries.size(); i++)
        {
            qs.emplace_back(queries[i], i);
        }
        sort(qs.begin(), qs.end());
        sort(intervals.begin(), intervals.end());

        auto cmp = [](pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        int i = 0;
        vector<int> result(queries.size());

        for (auto &[num, idx] : qs)
        {
            while (i < intervals.size() && intervals[i][0] <= num)
            {
                pq.emplace(intervals[i][1], intervals[i][1] - intervals[i][0] + 1);
                i++;
            }
            while (!pq.empty() && pq.top().first < num)
            {
                pq.pop();
            }
            result[idx] = pq.empty() ? -1 : pq.top().second;
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> intervals = {{4, 5}, {5, 8}, {1, 9}, {8, 10}, {1, 6}};
    vector<int> queries = {7, 9, 3, 9, 3};
    vector<int> result = Solution().minInterval(intervals, queries);
    printf("\nResult:");
    for (int num : result)
        printf(" %d", num);
    puts("");
}