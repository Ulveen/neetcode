#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = nums[0];
        int curr = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            curr = max(nums[i], curr + nums[i]);
            result = max(result, curr);
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = Solution().maxSubArray(nums);
    printf("\nResult: %d\n", result);
}