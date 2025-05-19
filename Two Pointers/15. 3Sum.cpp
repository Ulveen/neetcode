#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int len = nums.size();

        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = len - 1;
            while (j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                if (currSum < 0) j++;
                else if(currSum > 0) k--;
                else {
                    while(j + 1 < k && nums[j] == nums[j + 1]) j++;
                    while(k - 1 > j && nums[k] == nums[k - 1]) k--;
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> result = Solution().threeSum(nums);
    for (auto v : result) {
        for (int num : v) {
            cout << num << " ";
        }
        cout << endl;
    }
}