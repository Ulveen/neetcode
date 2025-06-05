#include <iostream>
#include <vector>
#include <math.h>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int start = 0, result = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[start])
            {
                start = i;
            }
            else
            {
                result = std::max(prices[i] - prices[start], result);
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = Solution().maxProfit(prices);
    std::cout << result;
}