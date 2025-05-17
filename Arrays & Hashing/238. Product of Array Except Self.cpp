#include<iostream>
#include<vector>
#include<malloc.h>

using namespace std;

class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const size_t size = nums.size();
        vector<int> a = {nums[0]}, b(size);

        b[size - 1] = nums[size - 1];

        for (int i = 1; i < size; i++) {
            a.push_back(a[i - 1] * nums[i]);
            b[size - i - 1] = b[size - i] * nums[size - i - 1];
        }

        vector<int> result = {b[1]};
        for (int i = 1; i < size; i++) {
            int e = a[i - 1];
            if (i + 1 < size) {
                e *= b[i + 1];
            }
            result.push_back(e);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    auto result = Solution().productExceptSelf(nums);
    
    for (const int& num : result) {
        cout << num << " ";
    }

}