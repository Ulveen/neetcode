#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class TimeMap
{
public:
    unordered_map<string, map<int, string>> tm;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        tm[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (tm.find(key) == tm.end())
        {
            return "";
        }
        map<int, string> &m = tm[key];
        auto it = m.upper_bound(timestamp);
        if (it != m.begin())
        {
            return (--it)->second;
        }
        return "";
    }
};

#include <variant>
using Element = variant<string, int>;
using Group = vector<Element>;

int main()
{
    vector<string> operations = {"TimeMap", "set", "get", "get", "set", "get", "get"};
    vector<Group> params = {{}, {"foo", "bar", 1}, {"foo", 1}, {"foo", 3}, {"foo", "bar2", 4}, {"foo", 4}, {"foo", 5}};

    TimeMap timeMap = TimeMap();

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "set")
        {
            auto key = get<string>(params[i][0]);
            auto value = get<string>(params[i][1]);
            auto timestamp = get<int>(params[i][2]);
            timeMap.set(key, value, timestamp);
            printf("SET key: %s, timestamp: %d, value: %s\n", key.c_str(), timestamp, value.c_str());
        }
        else if (operations[i] == "get")
        {
            auto key = get<string>(params[i][0]);
            auto timestamp = get<int>(params[i][1]);
            string result = timeMap.get(key, timestamp);
            if (result.length() == 0)
            {
                printf("%s NOT FOUND\n", key.c_str());
            }
            else
            {
                printf("%s FOUND: %s-%d\n", key.c_str(), result.c_str(), timestamp);
            }
        }
    }
}