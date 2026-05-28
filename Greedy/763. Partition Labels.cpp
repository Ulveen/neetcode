#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string& s)
    {
        int last[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            last[s[i] - 'a'] = i;
        }
        int start = 0;
        int end = 0;
        vector<int> result;
        for (int i = 0; i < s.length(); i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (end == i)
            {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};

int main()
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = Solution().partitionLabels(s);
    printf("\nResult:");
    for (int num : result)
        cout << ' ' << num;
    puts("");
}