#include <iostream>
#include <unordered_map>

class Solution
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        int n = s1.length(), m = s2.length();

        if (m < n)
        {
            return false;
        }

        std::unordered_map<char, int> map1, map2;

        for (int i = 0; i < n; i++)
        {
            map1[s1[i]]++;
            map2[s2[i]]++;
        }

        for (int i = 0; i <= m - n; i++)
        {
            if (map1 == map2)
                return true;
            if (map2[s2[i]] == 1)
                map2.erase(s2[i]);
            else
                map2[s2[i]]--;
            map2[s2[i + n]]++;
        }

        return map1 == map2;
    }
};

int main()
{
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";

    bool result = Solution().checkInclusion(s1, s2);
    printf("%s", result ? "True" : "False");
}