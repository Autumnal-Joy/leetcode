#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class DualSet {
    // x 个最高频率的数 <freq, num>
    multiset<pair<int, int>> mostFreq;
    // 剩余的数 <freq, num>
    multiset<pair<int, int>, std::greater<>> lessFreq;
    int x;

public:
    long long sum = 0;

    explicit DualSet(int x) : x(x) {}

    void adjust() {
        while (mostFreq.size() > x) {
            auto it = mostFreq.begin();
            lessFreq.insert(*it);
            sum -= 1ll * it->first * it->second;
            mostFreq.erase(it);
        }
        while (mostFreq.size() < x && !lessFreq.empty()) {
            auto it = lessFreq.begin();
            mostFreq.insert(*it);
            sum += 1ll * it->first * it->second;
            lessFreq.erase(it);
        }
    }

    void insert(pair<int, int> p) {
        if (mostFreq.empty() || *mostFreq.begin() <= p) {
            mostFreq.insert(p);
            sum += 1ll * p.first * p.second;
        } else {
            lessFreq.insert(p);
        }
        adjust();
    }

    void del(pair<int, int> p) {
        auto it = mostFreq.find(p);
        if (it != mostFreq.end()) {
            sum -= 1ll * it->first * it->second;
            mostFreq.erase(it);
            adjust();
        } else {
            lessFreq.erase(lessFreq.find(p));
        }
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x) {
        if (nums.size() <= x) {
            return {std::accumulate(nums.begin(), nums.end(), 0ll)};
        }

        auto counter = unordered_map<int, int>();
        for (int i = 0; i < k; ++i) {
            ++counter[nums[i]];
        }

        auto ds = DualSet(x);
        for (auto &p: counter) {
            ds.insert({p.second, p.first});
        }

        auto res = vector<long long>();
        res.push_back(ds.sum);

        for (int i = 1; i + k <= nums.size(); ++i) {
            ds.del({counter[nums[i - 1]], nums[i - 1]});
            --counter[nums[i - 1]];
            if (counter[nums[i - 1]] > 0) {
                ds.insert({counter[nums[i - 1]], nums[i - 1]});
            }

            if (counter[nums[i + k - 1]] > 0) {
                ds.del({counter[nums[i + k - 1]], nums[i + k - 1]});
            }
            ++counter[nums[i + k - 1]];
            ds.insert({counter[nums[i + k - 1]], nums[i + k - 1]});
            res.push_back(ds.sum);
        }

        return res;
    }
};

int main() {
    auto nums = vector<int>({1, 1, 2, 2, 3, 4, 2, 3});
    Solution s;
    s.findXSum(nums, 6, 2);
    return 0;
}
