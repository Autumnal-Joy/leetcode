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

class SegTree {
    vector<array<long long, 4>> tree;

    void set(const size_t node, const int x) {
        if (x > 0) {
            tree[node] = {0, 0, 0, x};
        } else {
            tree[node] = {0, 0, 0, 0};
        }
    }
    void maintain(const size_t node) {
        tree[node] = {
                std::max({tree[node * 2][0b01] + tree[node * 2 + 1][0b00], tree[node * 2][0b00] + tree[node * 2 + 1][0b10]}),
                std::max({tree[node * 2][0b01] + tree[node * 2 + 1][0b01], tree[node * 2][0b00] + tree[node * 2 + 1][0b11]}),
                std::max({tree[node * 2][0b11] + tree[node * 2 + 1][0b00], tree[node * 2][0b10] + tree[node * 2 + 1][0b10]}),
                std::max({tree[node * 2][0b11] + tree[node * 2 + 1][0b01], tree[node * 2][0b10] + tree[node * 2 + 1][0b11]}),
        };
    }

public:
    SegTree(const vector<int> &data) : tree(data.size() * 4) {
        build(1, 0, data.size() - 1, data);
    }
    void build(const size_t node, const size_t begin, const size_t end, const vector<int> &data) {
        if (begin == end) {
            set(node, data[begin]);
        } else {
            auto mid = (begin + end) >> 1;
            build(node * 2, begin, mid, data);
            build(node * 2 + 1, mid + 1, end, data);
            maintain(node);
        }
    }
    void update(const size_t node, const size_t begin, const size_t end, const size_t pos, const int x) {
        if (pos < begin || pos > end) return;
        if (pos == begin && pos == end) {
            set(node, x);
            return;
        }
        const auto mid = (begin + end) >> 1;
        update(node * 2, begin, mid, pos, x);
        update(node * 2 + 1, mid + 1, end, pos, x);
        maintain(node);
    }
    long long query(const size_t node, const size_t begin, const size_t end, const size_t left, const size_t right) {
        if (right < begin || left > end) return 0;
        if (begin <= left && end >= right) {
            return tree[node][0b11];
        }
        const auto mid = (begin + end) >> 1;
        return query(node * 2, begin, mid, left, right) + query(node * 2 + 1, mid, end, left, right);
    }
};

class Solution {
    int M = 1e9 + 7;

public:
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
        auto st = SegTree(nums);
        long long res = 0;
        for (const auto &q: queries) {
            st.update(1, 0, nums.size() - 1, q[0], q[1]);
            res += st.query(1, 0, nums.size() - 1, 0, nums.size() - 1);
        }
        return static_cast<int>(res % M);
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({3, 5, 9, -5, 1, 3});
    auto queries = vector<vector<int>>({{1, -2}, {0, -3}, {4, 6}});
    Solution().maximumSumSubsequence(nums, queries);
    return 0;
}
#endif
