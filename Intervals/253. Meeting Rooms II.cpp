#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> endTimes;

        for (int i = 0; i < intervals.size(); i++) {
            if (endTimes.empty() || endTimes.top() > intervals[i].start) {
                endTimes.push(intervals[i].end);
            }
            else {
                int endTime = max(endTimes.top(), intervals[i].end);
                endTimes.pop();
                endTimes.push(endTime);
            }
        }

        return endTimes.size();
    }
};

int main()
{
    vector<Interval> intervals = {{0, 40}, {5, 10}, {15, 20}};
    int result = Solution().minMeetingRooms(intervals);
    printf("\nResult: %d\n", result);
}