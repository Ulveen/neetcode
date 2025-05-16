#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> p;
        for (int i = 0; i < nums.size(); i++) {
            auto f = p.find(nums[i]);
            if (f != p.end() && f->second != i) {
                return {i, f->second};
            }
            p.insert({target - nums[i], i});
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = Solution().twoSum(nums, target);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}