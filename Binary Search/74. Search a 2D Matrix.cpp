#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0, right = matrix.size() - 1;
        int row = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target)
            {
                return true;
            }
            else if (matrix[mid][0] > target)
            {
                right = mid - 1;
            }
            else
            {
                if (matrix[mid] > matrix[row])
                {
                    row = mid;
                }
                left = mid + 1;
            }
        }

        if (row == 0 && target < matrix[row][0])
        {
            return false;
        }

        left = 0, right = matrix[0].size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target)
            {
                return true;
            }
            else if (matrix[row][mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 3;
    int result = Solution().searchMatrix(matrix, target);
    printf("%s", result ? "True" : "False");
}