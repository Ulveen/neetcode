#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        bool check[3] = { false };
        for (auto& t : triplets)
        {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;

            if (!check[0]) check[0] = t[0] == target[0];
            if (!check[1]) check[1] = t[1] == target[1];
            if (!check[2]) check[2] = t[2] == target[2];

            if (check[0] && check[1] && check[2]) return true;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> triplets = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
    vector<int> target = {2, 7, 5};
    bool result = Solution().mergeTriplets(triplets, target);
    printf("\nResult: %s\n", result ? "True" : "False");
}