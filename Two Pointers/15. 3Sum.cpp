#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
    private:
    string getHash(int a, int b, int c) {
        return to_string(a) + to_string(b) + to_string(c);
    }

    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        unordered_set<string> memo;

        int len = nums.size();

        for (int i = 0; i < len - 2; i++) {
            int j = i + 1, k = len - 1;
            while (j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                if (currSum == 0) {
                    if (memo.insert(getHash(nums[i], nums[j], nums[k])).second) {
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                }
                if (currSum < 0) {
                    j++;
                    continue;
                }
                k--;
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