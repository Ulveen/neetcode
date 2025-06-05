#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size(), length = m + n;

        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = 0, right = m;

        while (left <= right)
        {
            int i = (left + right) / 2;
            int j = (length + 1) / 2 - i;

            int maxLeft1 = i == 0 ? INT_MIN : nums1[i - 1];
            int minRight1 = i == m ? INT_MAX : nums1[i];

            int maxLeft2 = j == 0 ? INT_MIN : nums2[j - 1];
            int minRight2 = j == n ? INT_MAX : nums2[j];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                if (length % 2 == 1)
                {
                    return max(maxLeft1, maxLeft2);
                }
                return ((double)max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
            }
            else if (maxLeft1 > minRight2)
            {
                right = i - 1;
            }
            else
            {
                left = i + 1;
            }
        }

        return 0;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7, 8};
    double result = Solution().findMedianSortedArrays(nums1, nums2);
    cout << result;
}

//               i
// A = [1, 2, 3, 4, 5]
//            j
// B = [1, 2, 3, 4, 5, 6, 7, 8]
// total = 13
// mid = 6
// median = 4