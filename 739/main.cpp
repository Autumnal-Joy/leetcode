#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int> &temperatures) {
        vector<int> res(temperatures.size());
        deque<int> stack;
        for (int i = 0; i < temperatures.size(); i++) {
            if (stack.empty() || temperatures[stack.back()] >= temperatures[i]) {
                stack.emplace_back(i);
            } else {
                while (!stack.empty() && temperatures[stack.back()] < temperatures[i]) {
                    res[stack.back()] = i - stack.back();
                    stack.pop_back();
                }
                stack.emplace_back(i);
            }
        }
        while (!stack.empty()) {
            res[stack.back()] = 0;
            stack.pop_back();
        }

        return res;
    }
};

int main() {
    auto s = Solution();
    auto answer =
            s.dailyTemperatures(vector<int>{73, 74, 75, 71, 69, 72, 76, 73});
    std::copy(answer.begin(), answer.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
