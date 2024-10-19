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
    int trap(vector<int> &height) {
        auto n = static_cast<int>(height.size());

        auto sum = 0;
        auto st = stack<int>();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                const auto bottom = height[st.top()];
                st.pop();
                if (st.empty()) {
                    break;
                }
                const auto up = std::min({height[st.top()], height[i]});
                const auto left = st.top();
                const auto right = i;
                sum += (right - left - 1) * (up - bottom);
            }
            st.push(i);
        }
        return sum;
    }
};

int main() {
    auto s = Solution();
    auto height = vector<int>({5, 2, 1, 2, 1, 5});
    cout << s.trap(height);
    return 0;
}
