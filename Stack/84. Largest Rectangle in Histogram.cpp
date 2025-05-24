#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public: 
    int largestRectangleArea(vector<int>& height) {
        int maxHeight = 0, n = height.size();

        for (int i = 0; i < n; i++) {
            int minHeight = height[i];
            for (int j = i; j < n; j++) {
                minHeight = min(minHeight, height[j]);
                maxHeight = max(maxHeight, minHeight * (j - i + 1));
            }
        }

        return maxHeight;
    }
};

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};
    int result = Solution().largestRectangleArea(height);
    cout << result;
}