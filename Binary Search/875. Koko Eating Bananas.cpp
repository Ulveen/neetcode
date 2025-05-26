#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canFinish(vector<int> &piles, int speed, int h)
    {
        int time = 0;
        for (int pile : piles)
        {
            time += (pile + speed - 1) / speed;
            if (time > h)
            {
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxVal = *max_element(piles.begin(), piles.end());
        int left = 1, right = maxVal, result = maxVal;

        while (left <= right)
        {
            int mid = (right + left) / 2;
            bool flag = canFinish(piles, mid, h);
            if (!flag)
            {
                left = mid + 1;
                continue;
            }
            if (mid < result)
            {
                result = mid;
            }
            right = mid - 1;
        }

        return result;
    }
};

int main()
{
    vector<int> piles = {30,11,23,4,20};
    int h = 6;
    int result = Solution().minEatingSpeed(piles, h);
    cout << result;
}

/*

3,6,7,11
h = 8
Output: 4

4,11,20,23,30
h = 5
Output: 30

4,11,20,23,30
h = 6
Output: 23

*/