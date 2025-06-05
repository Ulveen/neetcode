#include <iostream>
#include <unordered_map>
#include <set>

struct Entry
{
    char ch;
    int count;

    bool operator<(const Entry &other) const
    {
        if (count != other.count)
            return count > other.count;
        return ch < other.ch;
    }
};

class FrequencyTracker
{
    std::unordered_map<char, int> freq;

public:
    std::set<Entry> sorted;
    void increment(char ch)
    {
        if (freq.count(ch))
        {
            sorted.erase(Entry{ch, freq[ch]});
        }
        freq[ch]++;
        sorted.insert(Entry{ch, freq[ch]});
    }

    void decrement(char ch)
    {
        sorted.erase(Entry{ch, freq[ch]});
        freq[ch]--;
        if (freq[ch] > 0)
            sorted.insert(Entry{ch, freq[ch]});
    }
};

class Solution
{
public:
    int characterReplacement(std::string s, int k)
    {
        int result = 0, left = 0, len = s.length();
        FrequencyTracker ft;

        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            ft.increment(c);
            int subLen = i - left + 1;
            auto e = *ft.sorted.begin();

            if (subLen - e.count <= k)
                continue;

            result = std::max(result, subLen - 1);
            while (i - left + 1 - e.count > k)
            {
                ft.decrement(s[left++]);
                e = *ft.sorted.begin();
            }
        }

        return std::max(result, len - left);
    }
};

int main()
{
    std::string s = "AAAAABBBBCBB";
    int k = 4;
    int result = Solution().characterReplacement(s, k);
    std::cout << result;
}