#include<unordered_set>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> memo;
        for (auto num : nums) {
            if (!memo.insert(num).second) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    bool result = Solution().containsDuplicate(nums);
    printf("%s", result ? "true" : "false");
}