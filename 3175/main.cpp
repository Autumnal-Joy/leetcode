#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findWinningPlayer(vector<int> &skills, int k) {
        if (k >= skills.size()) {
            k = skills.size() - 1;
        }
        auto idx = vector<int>(skills.size());
        std::iota(idx.begin(), idx.end(), 0);
        auto dq = deque<int>(idx.begin(), idx.end());
        int cnt = 0;
        while (true) {
            auto a = dq.front();
            dq.pop_front();
            auto b = dq.front();
            dq.pop_front();
            if (skills[a] > skills[b]) {
                ++cnt;
                dq.push_front(a);
                dq.push_back(b);
            } else {
                cnt = 1;
                dq.push_front(b);
                dq.push_back(a);
            }
            if (cnt == k) {
                break;
            }
        }
        return dq.front();
    }
};

int main() {
    auto nums = vector<int>({7, 11});
    auto s = Solution();
    cout << s.findWinningPlayer(nums, 2);
    return 0;
}
