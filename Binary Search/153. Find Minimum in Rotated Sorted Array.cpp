#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int left = 0, right = n;
        while (left <= right)
        {
            int mid = (right + left) / 2;
            if ((mid != 0 && nums[mid] < nums[mid - 1]))
            {
                return nums[mid];
            }
            if (mid != n && nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return nums[0];
    }
};

int main()
{
    vector<int> nums = {5,1,2,3,4};
    int result = Solution().findMin(nums);
    cout << result;
}

/*

1. 1 2 3 4 5 -> left

2. 5 1 2 3 4 -> left

3. 3 4 5 1 2 -> right

4. 2 3 4 5 1 -> right


*/