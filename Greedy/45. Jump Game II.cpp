#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int start = 0;
        int farthest = 0;
        int jumps = 0;
        int next = 0;

        while (farthest < nums.size() - 1)
        {
            for (int i = start; i <= farthest; i++)
            {
                next = max(next, i + nums[i]);
            }
            start = farthest + 1;
            farthest = next;
            jumps++;
        }

        return jumps;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    int result = Solution().jump(nums);
    printf("\nResult: %d\n", result);
}