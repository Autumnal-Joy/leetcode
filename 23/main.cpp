#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeLists(ListNode *l1, ListNode *l2) {
        auto head = ListNode();
        auto current = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1) {
            current->next = l1;
        } else {
            current->next = l2;
        }
        return head.next;
    }

    ListNode *merge(vector<ListNode *> &lists, int start, int end) {
        if (start == end) {
            return nullptr;
        }
        if (start + 1 == end) {
            return lists[start];
        }
        int mid = start + (end - start) / 2;
        auto left = merge(lists, start, mid);
        auto right = merge(lists, mid, end);
        return mergeLists(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = static_cast<int>(lists.size());
        return merge(lists, 0, n);
    }
};

int main() {
    auto s = Solution();
    return 0;
}
