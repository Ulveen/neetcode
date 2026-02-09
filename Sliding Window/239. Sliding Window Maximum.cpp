#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        priority_queue<int> pq;
        unordered_map<int, int> um;

        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++)
        {
            result.push_back(pq.top());
            um[nums[i - k]]++;
            int top = pq.top();
            while (um[top] > 0)
            {
                pq.pop();
                um[top]--;
                top = pq.top();
            }
            pq.push(nums[i]);
        }

        result.push_back(pq.top());

        return result;
    }
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = Solution().maxSlidingWindow(nums, k);
    for (int num : result)
    {
        cout << num << " ";
    }
}