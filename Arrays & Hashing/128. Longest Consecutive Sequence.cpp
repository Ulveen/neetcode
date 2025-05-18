#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxCount = 0;

        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int currCount = 1;
                int prev = num;
                while(s.find(++prev) != s.end()) {
                    currCount++;
                }
                maxCount = max(maxCount, currCount);
            }
        }

        return maxCount;
    }
};

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    int result = Solution().longestConsecutive(nums);
    cout << result;
}