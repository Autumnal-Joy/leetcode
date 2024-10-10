#include <limits>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        auto leftMin = vector<int>(nums.size(), -1), rightMin = vector<int>(nums.size(), static_cast<int>(nums.size()));
        auto leftMax = vector<int>(nums.size(), -1), rightMax = vector<int>(nums.size(), static_cast<int>(nums.size()));

        auto minStack = stack<int>(), maxStack = stack<int>();
        for (int i = 0; i < nums.size(); ++i) {
            while (!minStack.empty() && nums[minStack.top()] > nums[i]) {
                rightMin[minStack.top()] = i;
                minStack.pop();
            }
            leftMin[i] = minStack.empty() ? -1 : minStack.top();
            minStack.push(i);

            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i]) {
                rightMax[maxStack.top()] = i;
                maxStack.pop();
            }
            leftMax[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(i);
        }

        long long maxSum = 0;
        long long minSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxSum += 1ll * (i - leftMax[i]) * (rightMax[i] - i) * nums[i];
            minSum += 1ll * (i - leftMin[i]) * (rightMin[i] - i) * nums[i];
        }

        return maxSum - minSum;
    }
};

int main() {
    Solution s;
    auto v = vector<int>({1, 2, 3});
    cout << s.subArrayRanges(v) << endl;
    return 0;
}
