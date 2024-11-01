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
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        auto st = stack<int>();
        auto mp = unordered_map<int, int>();
        for (int i = 0; i < pushed.size(); ++i) {
            mp[pushed[i]] = i;
        }
        int i = 0, j = 0;
        while (j < popped.size()) {
            while (i <= mp[popped[j]]) {
                st.push(pushed[i++]);
            }
            if (st.top() != popped[j]) {
                return false;
            }
            st.pop();
            ++j;
        }
        return true;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
