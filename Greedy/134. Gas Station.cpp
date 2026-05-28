#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0;
        while (start < gas.size())
        {
            if (gas[start] < cost[start])
            {
                start++;
                continue;
            }

            int curr = gas[start] - cost[start];
            int i = (start + 1) % gas.size();

            while (i != start)
            {
                curr += gas[i] - cost[i];
                if (curr < 0) break;
                i = (i + 1) % gas.size();
            }

            if (i == start)
            {
                return start;
            }
            else if (i < start)
            {
                break;
            }
            start = i;
        }
        return -1;
    }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int result = Solution().canCompleteCircuit(gas, cost);
    printf("\nResult: %d\n", result);
}