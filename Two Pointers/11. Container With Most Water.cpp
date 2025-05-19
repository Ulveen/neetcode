#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
    public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, result = 0;
        while (l < r) {
            result = max(min(height[l], height[r]) * (r - l), result);
            if (height[l] > height[r]) r--;
            else l++;
        }
        return result;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = Solution().maxArea(height);
    cout << result;
}