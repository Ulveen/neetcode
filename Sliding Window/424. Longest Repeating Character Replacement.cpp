#include <iostream>

class Solution
{
public:
    int characterReplacement(std::string s, int k)
    {
        int n = s.size();
        int count[26] = {0};
        int left = 0, maxCount = 0, answer = 0;

        for (int i = 0; i < n; i++)
        {
            char c = s[i] - 'A';
            count[c]++;
            maxCount = std::max(maxCount, count[c]);

            while ((i - left + 1) - maxCount > k)
            {
                count[s[left] - 'A']--;
                left++;
            }

            answer = std::max(answer, i - left + 1);
        }

        return answer;
    }
};

int main()
{
    std::string s = "AAAAABBBBCBB";
    int k = 4;
    int result = Solution().characterReplacement(s, k);
    std::cout << result;
}