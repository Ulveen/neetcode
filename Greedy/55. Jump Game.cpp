#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int farthest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (farthest < i)
                break;
            farthest = max(farthest, i + nums[i]);
        }
        return farthest >= nums.size() - 1;
    }
};

int main()
{
    vector<int> nums = {1, 2, 0, 1, 0};
    bool result = Solution().canJump(nums);
    printf("\nResult: %s\n", result ? "True" : "False");
}