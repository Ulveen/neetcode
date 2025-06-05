#include <iostream>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int len = s.length();
        int result = std::min(1, len), left = 0;
        std::unordered_map<int, int> map;

        for (int i = 0; i < len; i++)
        {
            if (map[s[i]] == 1)
            {
                result = std::max(result, i - left);
                int j;
                for (j = left; j < i; j++)
                {
                    if (s[j] == s[i])
                    {
                        break;
                    }
                    map[s[j]] = 0;
                }
                left = j + 1;
            }
            else
            {
                map[s[i]] = 1;
            }
        }

        return std::max(result, len - left);
    }
};

int main()
{
    std::string s = "abcabccbb";
    int result = Solution().lengthOfLongestSubstring(s);
    std::cout << result;
}