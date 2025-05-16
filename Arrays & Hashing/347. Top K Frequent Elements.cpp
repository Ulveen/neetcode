#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#define PII pair<int, int>

using namespace std;

class Compare {
    public:
    bool operator()  (PII a, PII b) {
        return a.second < b.second;
    }
};

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        priority_queue<PII, vector<PII>, Compare> pq;
        for (PII e : counts) {
            pq.push(e);
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = Solution().topKFrequent(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
}