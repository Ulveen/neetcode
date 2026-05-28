#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<bool> same(3, false);
        bool candidate = false;
        for (vector<int>& t : triplets)
        {
            vector<bool> flags(3, false); 
            bool valid = true;
            for (int i = 0; i < 3; i++)
            {
                if (t[i] > target[i]) valid = false;
                else if (t[i] == target[i]) flags[i] = true;
            }
            if (valid){
                for (int i = 0; i < 3; i++) {
                    same[i] = same[i] || flags[i];
                }
                candidate = true;
            }
        }
        return same[0] && same[1] && same[2] && candidate;
    }
};

int main()
{
    vector<vector<int>> triplets = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
    vector<int> target = {2, 7, 5};
    bool result = Solution().mergeTriplets(triplets, target);
    printf("\nResult: %s\n", result ? "True" : "False");
}