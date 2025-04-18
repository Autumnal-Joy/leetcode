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

template<typename T, size_t N>
class HashArray {
public:
    size_t operator()(const array<T, N> &arr) const {
        return std::reduce(arr.begin(), arr.end(), size_t{}, [hasher = hash<T>()](const size_t seed, const T &val) {
            return seed ^ hasher(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        });
    }
};

class Solution {
public:
    static bool isInterleave(const string &s1, const string &s2, const string &s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        auto us = unordered_set<array<int, 2>, HashArray<int, 2>>();
        us.insert({0, 0});
        for (int i = 0; i < s3.size() && !us.empty(); ++i) {
            decltype(us) temp{};
            for (const auto &[x, y]: us) {
                if (s1[x] == s3[i]) {
                    temp.insert({x + 1, y});
                }
                if (s2[y] == s3[i]) {
                    temp.insert({x, y + 1});
                }
            }
            us = std::move(temp);
        }
        return !us.empty();
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
