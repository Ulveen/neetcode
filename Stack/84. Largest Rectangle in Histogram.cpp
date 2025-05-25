#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, n = heights.size();
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && heights[i] <= heights[st.top()]) {
                int height = heights[st.top()]; st.pop();
                int width = i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        while (st.top() != -1) {
            int height = heights[st.top()]; st.pop();
            int width = n - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};
    int result = Solution().largestRectangleArea(height);
    cout << result;
}