#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int currSum = numbers[l] + numbers[r];
            if (currSum == target) {
                return {l + 1, r + 1};
            }
            if (currSum > target) {
                r--;
                continue;
            }
            l++;
        }
        return {};
    }
};

int main() {
    vector<int> numbers = {
        2,7,11,15
    };
    int target = 9;
    vector<int> result = Solution().twoSum(numbers, target);
    for (int num : result) {
        cout << num << " ";
    }
}