#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        double median = 0;

        vector<int> combined;

        int left = 0, right = 0;

        while (left < m && right < n)
        {
            if (nums1[left] < nums2[right])
            {
                combined.push_back(nums1[left++]);
            }
            else
            {
                combined.push_back(nums2[right++]);
            }
        }

        while (left < m)
        {
            combined.push_back(nums1[left++]);
        }

        while (right < n)
        {
            combined.push_back(nums2[right++]);
        }

        int mid = m + n;
        bool isOdd = mid % 2 == 1;
        mid /= 2;

        if (isOdd)
        {
            median = combined[mid];
        }
        else
        {
            median = ((double)combined[mid] + combined[mid - 1]) / 2;
        }

        return median;
    }
};

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double result = Solution().findMedianSortedArrays(nums1, nums2);
    cout << result;
}