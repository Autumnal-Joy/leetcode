#include <bits/stdc++.h>

using namespace std;

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
TreeNode *vec2tree(const vector<int> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    auto *root = new TreeNode(vec[0]);
    auto q = queue<TreeNode *>();
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        auto node = q.front();
        q.pop();
        if (vec[i] != -1) {
            node->left = new TreeNode(vec[i]);
            q.push(node->left);
        }
        if (i + 1 < vec.size() && vec[i + 1] != -1) {
            node->right = new TreeNode(vec[i + 1]);
            q.push(node->right);
        }
    }
    return root;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};
ListNode *vec2list(const vector<int> &vec) {
    ListNode head;
    ListNode *p = &head;
    for (const auto &val: vec) {
        p->next = new ListNode(val);
        p = p->next;
    }
    return head.next;
}
vector<vector<int>> read(const string &filename) {
    auto res = vector<vector<int>>();
    auto ifs = ifstream(filename);
    auto line = string();
    while (getline(ifs, line)) {
        auto vec = vector<int>();
        auto iss = istringstream(line);
        for (int val; iss >> val;) {
            vec.push_back(val);
        }
        res.push_back(std::move(vec));
    }
    return res;
}
void write(const vector<int> &data, const string &filename) {
    auto ofs = ofstream(filename);
    ranges::copy(data, ostream_iterator<int>(ofs, " "));
    ofs << '\n';
}
void write(const vector<vector<int>> &data, const string &filename) {
    auto ofs = ofstream(filename);
    for (const auto &line: data) {
        ranges::copy(line, ostream_iterator<int>(ofs, " "));
        ofs << '\n';
    }
}
#endif

long long quickMod(long long x, long long n, long long Mod) {
    long long res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % Mod;
        }
        x = x * x % Mod;
        n >>= 1;
    }
    return res;
}

class Solution {
    long long MOD = 1e9 + 7;
    using PII = pair<long long, int>;

public:
    vector<int> getFinalState(vector<int> &nums, const int k, const int multiplier) {
        if (multiplier == 1) return nums;

        const auto n = nums.size();
        auto cnt = vector(n, 0);
        const auto maxVal = ranges::max(nums);
        for (int i = 0; i < n; ++i) {
            cnt[i] = static_cast<int>(std::log(1.0 * maxVal / nums[i]) / std::log(multiplier));
        }
        const auto sum = std::reduce(cnt.begin(), cnt.end(), 0);
        auto pq = priority_queue<PII, vector<PII>, std::greater<>>();
        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);
        }
        if (k < sum) {
            for (int i = 0; i < k; ++i) {
                const auto [_, idx] = pq.top();
                pq.pop();
                nums[idx] = nums[idx] * multiplier;
                pq.emplace(nums[idx], idx);
            }
        } else {
            for (int i = 0; i < sum; ++i) {
                const auto [_, idx] = pq.top();
                pq.pop();
                nums[idx] = nums[idx] * multiplier;
                pq.emplace(nums[idx], idx);
            }
            auto [repeat, rem] = std::lldiv(k - sum, n);
            for (int i = 0; i < rem; ++i) {
                const auto [_, idx] = pq.top();
                pq.pop();
                nums[idx] = static_cast<int>(1ll * nums[idx] * multiplier % MOD);
            }
            if (repeat) {
                for (int i = 0; i < n; ++i) {
                    nums[i] = static_cast<int>(nums[i] * quickMod(multiplier, repeat, MOD) % MOD);
                }
            }
        }
        return nums;
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector{2, 5, 1, 5, 1, 1, 3, 5};
    Solution().getFinalState(nums, 5, 2);
    return 0;
}
#endif
