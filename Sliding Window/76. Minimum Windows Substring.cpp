#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> counter;
        unordered_set<char> charSet;
        for (char c : t)
        {
            counter[c]++;
            charSet.insert(c);
        }

        int count = charSet.size();
        int minCount = INT_MAX;

        int start = 0;
        int minStart = -1;
        int minEnd = -1;

        for (int i = 0; i < s.size(); i++)
        {
            if (charSet.find(s[i]) == charSet.end())
            {
                continue;
            }

            counter[s[i]]--;
            if (counter[s[i]] != 0)
            {
                continue;
            }

            count--;

            if (count == 0)
            {
                for (int j = start; j <= i; j++)
                {
                    start++;
                    if (charSet.find(s[j]) != charSet.end())
                    {
                        counter[s[j]]++;
                        if (counter[s[j]] == 1)
                        {
                            count++;
                            if (i - start < minCount)
                            {
                                minCount = i - start;
                                minStart = start - 1;
                                minEnd = i;
                            }
                            break;
                        }
                    }
                }
            }
        }

        if (minStart != -1)
        {
            return s.substr(minStart, minEnd - minStart + 1);
        }

        return "";
    }
};

int main()
{
    string s = "a";
    string t = "a";

    string result = Solution().minWindow(s, t);
    cout << result;
}