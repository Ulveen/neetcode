#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;

class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int maxCount = 0, currCount = 0;
        int prev = *s.begin();

        for (auto itr = s.begin(); itr != s.end(); itr++) {
            if (*itr - prev != 1) {
                maxCount = max(currCount, maxCount);
                currCount = 1;
            }
            else {
                currCount++;
            }
            prev = *itr;
        }

        return max(maxCount, currCount);
    }
};

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    int result = Solution().longestConsecutive(nums);
    cout << result;
}