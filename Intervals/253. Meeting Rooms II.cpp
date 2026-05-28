#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

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
        vector<array<int, 2>> rooms;

        for (int i = 0; i < intervals.size(); i++) {
            bool flag = false;
            for (int j = 0; j < rooms.size(); j++) {
                if (rooms[j][1] <= intervals[i].start) {
                    rooms[j][1] = max(rooms[j][1], intervals[i].end);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                rooms.push_back({intervals[i].start, intervals[i].end});
            }
        }

        return rooms.size();
    }
};

int main()
{
    vector<Interval> intervals = {{0, 40}, {5, 10}, {15, 20}};
    int result = Solution().minMeetingRooms(intervals);
    printf("\nResult: %d\n", result);
}