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
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        auto in = vector<int>(numCourses);
        auto out = vector<unordered_set<int>>(numCourses);
        for (const auto &p: prerequisites) {
            if (!out[p[1]].contains(p[0])) {
                in[p[0]]++;
                out[p[1]].insert(p[0]);
            }
        }
        auto start = deque<int>();
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                start.push_back(i);
            }
        }
        auto result = vector<int>();
        while (!start.empty()) {
            auto course = start.front();
            start.pop_front();
            result.push_back(course);
            for (const auto &c: out[course]) {
                in[c]--;
                if (in[c] == 0) {
                    start.push_back(c);
                }
            }
        }
        return result.size() == numCourses ? result : vector<int>();
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
