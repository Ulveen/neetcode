#include <iostream>
#include <unordered_map>

class Solution
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        int n = s1.length(), m = s2.length();

        if (m < n)
            return false;

        int map1[26] = {0}, map2[26] = {0};

        for (int i = 0; i < n; i++)
        {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }

        for (int i = 0; i < m - n; i++)
        {
            if (std::memcmp(map1, map2, 26 * sizeof(int)) == 0)
                return true;
            map2[s2[i] - 'a']--;
            map2[s2[i + n] - 'a']++;
        }

        return std::memcmp(map1, map2, 26 * sizeof(int)) == 0;
    }
};

int main()
{
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";

    bool result = Solution().checkInclusion(s1, s2);
    printf("%s", result ? "True" : "False");
}