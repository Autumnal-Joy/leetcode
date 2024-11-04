#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#ifdef LEETCODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
public:
    int openLock(const vector<string> &deadends, const string &target) {
        auto dead = unordered_set(deadends.begin(), deadends.end());
        if (dead.contains("0000")) return -1;
        if (target == "0000") return 0;
        auto dq = deque<string>();
        dq.emplace_back("0000");
        auto visited = unordered_set<string>();
        visited.emplace("0000");
        int step = 0;
        while (!dq.empty()) {
            auto n = dq.size();
            ++step;
            while (n--) {
                auto front = dq.front();
                dq.pop_front();
                for (int i = 0; i < 4; ++i) {
                    auto prev = front, next = front;
                    prev[i] = (prev[i] - '0' + 9) % 10 + '0';
                    next[i] = (next[i] - '0' + 1) % 10 + '0';
                    if (prev == target || next == target) {
                        return step;
                    }
                    if (!dead.contains(prev) && !visited.contains(prev)) {
                        dq.push_back(prev);
                        visited.insert(std::move(prev));
                    }
                    if (!dead.contains(next) && !visited.contains(next)) {
                        dq.push_back(next);
                        visited.insert(std::move(next));
                    }
                }
            }
        }
        return -1;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
