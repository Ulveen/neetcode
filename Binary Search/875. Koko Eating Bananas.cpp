#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int calcTime(vector<int>& piles, int speed, int n)
    {
        if (speed == 0)
        {
            return INT_MAX;
        }
        int left = 0, right = n - 1, start = n;

        while (left <= right)
        {
            int mid = (right + left) / 2;
            if (piles[mid] > speed)
            {
                if (mid < start)
                {
                    start = mid;
                }
                right = mid - 1;
                continue;
            }
            left = mid + 1;
        }

        int time = start;

        for (int i = start; i < n; i++)
        {
            time += (piles[i] + speed - 1) / speed;
        }

        return time;

    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size(), maxVal = *max_element(piles.begin(), piles.end());

        if (h == n)
        {
            return maxVal;
        }
    
        sort(piles.begin(), piles.end());
        int left = 1, right = piles[n - 1], result = INT_MAX;

        while (left <= right)
        {
            int mid = (right + left) / 2;
            int time = calcTime(piles, mid, n);
            if (time > h)
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
    vector<int> piles = {4,11,20,23,30};
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