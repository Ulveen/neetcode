#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> indexes;
        vector<vector<string>> result;

        int counter = 0;

        for (string str: strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            auto idx = indexes.find(copy);
            if (idx != indexes.end()) {
                result[idx->second].push_back(str);
            }
            else {
                indexes.insert({copy, counter++});
                result.push_back({str});
            }
        }

        return result;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = Solution().groupAnagrams(strs);

    for (vector<string> vec : result) {
        for (string str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
}