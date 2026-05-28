#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> counter;
        for (int num : hand)
        {
            counter[num]++;
        }

        int groups = hand.size() / groupSize;
        while (groups > 0)
        {
            auto first = *counter.begin();
            if (first.second > groups)
                return false;

            int num = first.first;
            int count = first.second;
            groups -= count;
            counter.erase(counter.begin());

            for (int i = 1; i < groupSize; i++)
            {
                auto find = counter.find(++num);
                if (find == counter.end() || find->second < count)
                    return false;
                if (find->second == count)
                    counter.erase(find);
                else
                    find->second -= count;
            }
        }

        return true;
    }
};

int main()
{
    vector<int> hand = { 1,2,3,6,2,3,4,7,8 };
    int groupSize = 3;
    bool result = Solution().isNStraightHand(hand, groupSize);
    printf("\nResult: %s\n", result ? "True" : "False");
}