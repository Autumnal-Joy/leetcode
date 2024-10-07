#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto [num, count] : freq) {
            bucket[count].push_back(num);
        }

        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; --i) {
            for (auto num : bucket[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
