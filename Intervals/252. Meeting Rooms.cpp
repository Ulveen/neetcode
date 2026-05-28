#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<Interval> intervals = {{0, 30}, {5, 10}, {15, 20}};
    bool result = Solution().canAttendMeetings(intervals);
    printf("\nResult: %s\n", result ? "True" : "False");
}