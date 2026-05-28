#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        k--;
        vector<vector<pair<int, int>>> list(n);
        vector<int> dist(n, INT_MAX);

        auto cmp = [&](int a, int b) { 
            return dist[a] > dist[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (auto& time : times) {
            if (time[0] - 1 == k) {
                dist[time[1] - 1] = time[2];
                pq.push(time[1] - 1);
            }
            else {
                list[time[0] - 1].emplace_back(time[1] - 1, time[2]);
            }
        }

        while (!pq.empty())
        {
            int idx = pq.top(); pq.pop();
            for (auto &it : list[idx])
            {
                int newTime = dist[idx] + it.second;
                if (newTime < dist[it.first])
                {
                    dist[it.first] = newTime;
                    pq.push(it.first);
                }
            }
        }

        int result = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (i == k) continue;
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