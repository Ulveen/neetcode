#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, vector<int>> mapping;
        for (int i = 0; i < wordList.size(); i++)
        {
            string &word = wordList[i];
            for (int j = 0; j < word.length(); j++)
            {
                char c = word[j];
                word[j] = '*';
                mapping[word].push_back(i);
                word[j] = c;
            }
        }

        vector<bool> seen(wordList.size(), false);
        queue<pair<int, int>> q;
        
        for (int i = 0; i < beginWord.size(); i++)
        {
            char c = beginWord[i];
            beginWord[i] = '*';

            auto it = mapping.find(beginWord);
            if (it != mapping.end())
            {
                for (int j : it->second)
                {
                    if (!seen[j])
                    {
                        seen[j] = true;
                        q.push({ j, 1 });
                    }
                }
                mapping.erase(it);
            }
            beginWord[i] = c;
        }

        while (!q.empty())
        {
            auto [idx, steps] = q.front(); q.pop();
            if (wordList[idx] == endWord) return steps + 1;

            for (int i = 0; i < wordList[idx].size(); i++)
            {
                char c = wordList[idx][i];
                wordList[idx][i] = '*';

                auto it = mapping.find(wordList[idx]);
                if (it != mapping.end())
                {
                    for (int j : it->second)
                    {
                        if (!seen[j])
                        {
                            seen[j] = true;
                            q.push({ j, steps + 1 });
                        }
                    }
                    mapping.erase(it);
                }
                wordList[idx][i] = c;
            }
        }

        return 0;
    }
};

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = Solution().ladderLength(beginWord, endWord, wordList);
    cout << "Result: " << result << endl;
}
