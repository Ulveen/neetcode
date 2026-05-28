#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> list(n);
        for (auto time : times)
        {
            list[time[0] - 1].emplace_back(time[1] - 1, time[2]);
        }
        auto cmp = [](pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        vector<int> dist(n, INT_MAX);

        for (auto &it : list[k - 1])
        {
            dist[it.first] = it.second;
            pq.emplace(it.first, it.second);
        }

        while (!pq.empty())
        {
            auto [idx, time] = pq.top();
            pq.pop();
            for (auto &it : list[idx])
            {
                int newTime = time + it.second;
                if (newTime < dist[it.first])
                {
                    dist[it.first] = newTime;
                    pq.emplace(it.first, newTime);
                }
            }
        }

        int result = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (i == k - 1) continue;
            if (dist[i] == INT_MAX) return -1;
            result = max(result, dist[i]);
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    int result = Solution().networkDelayTime(times, n, k);
    printf("\nResult: %d\n", result);
}