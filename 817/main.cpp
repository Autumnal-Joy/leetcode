#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  explicit ListNode(const vector<int> &nums) {
    this->val = nums[0];

    auto head = this;
    for (int i = 1; i < nums.size(); i++) {
      head = head->next = new ListNode(nums[i]);
    }
  }
  ~ListNode() {
    auto head = this;
    while (head) {
      auto temp = head->next;
      delete head;
      head = temp;
    }
  }
};

class Solution {
public:
  int numComponents(ListNode *head, vector<int> &nums) {
    auto s = unordered_set<int>(nums.begin(), nums.end());
    int cnt = 0;
    bool componentStart = false;
    while (head) {
      auto val = head->val;
      if (s.count(val)) {
        componentStart = true;
      } else if (componentStart) {
        cnt++;
        componentStart = false;
      }

      head = head->next;
    }
    if (componentStart) {
      cnt++;
    }
    return cnt;
  }
};

int main() {
  auto s = Solution();
  auto head = new ListNode({0, 1, 2});
  auto nums = vector<int>{0, 2};
  cout << s.numComponents(head, nums) << endl;
  delete head;
  return 0;
}
