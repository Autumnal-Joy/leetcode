#include <stack>
#include <vector>

using namespace std;

// 1,2,3,4,1,2,3,4,1,2,3,4
class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        auto minStack = stack<int>();
        int start = static_cast<int>(nums.size()), end = -1;
        int max = numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); ++i) {
            while (!minStack.empty() && nums[minStack.top()] > nums[i]) {
                start = std::min({start, minStack.top()});
                minStack.pop();
            }
            if (nums[i] < max) {
                end = i;
            } else {
                max = nums[i];
            }
            minStack.push(i);
        }
        return std::max({end - start + 1, 0});
    }
};

int main() { return 0; }
