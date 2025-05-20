#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    int trap(vector<int>& height) {
        int len = height.size(), i = 0, total = 0, temp = 0;
        while (i < len && height[i] == 0) {
            i++;
        }
        if (i >= len - 1) return 0;

        int curr = i++;
        while (i < len - 1) {
            if (height[i] >= height[curr]) {
                if (i - curr > 1) {
                    total += (min(height[i], height[curr]) * (i - curr - 1) - temp);
                }
                curr = i;
                temp = 0;
            }
            else {
                temp += height[i];
            }
            i++;
        }
        
        if (height[i] >= height[curr]) {
            if (i - curr > 1) {
                total += (min(height[i], height[curr]) * (i - curr - 1) - temp);
            }
        }

        i = len - 1, temp = 0;
        curr = i--;
        while (i > 0) {
            if (height[i] > height[curr]) {
                if (curr - i > 1) {
                    total += (min(height[i], height[curr]) * (curr - i - 1) - temp);
                }
                curr = i;
                temp = 0;
            }
            else {
                temp += height[i];
            }
            i--;
        }

        if (height[i] > height[curr]) {
            if (curr - i > 1) {
                total += (min(height[i], height[curr]) * (curr - i - 1) - temp);
            }
            curr = i;
            temp = 0;
        }

        return total;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = Solution().trap(height);
    cout << result;
}