#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *low = nullptr, *high = nullptr;
        ListNode *head1 = nullptr, *head2 = nullptr;
        auto curser = head;
        while (curser) {
            if (curser->val < x) {
                if (!low) {
                    low = curser;
                    head1 = low;
                } else {
                    low->next = curser;
                    low = low->next;
                }
            } else {
                if (!high) {
                    high = curser;
                    head2 = high;
                } else {
                    high->next = curser;
                    high = high->next;
                }
            }
            curser = curser->next;
        }
        if (low) {
            low->next = head1;
        }
        if (high) {
            high->next = nullptr;
        }
        return head1 ? head1 : head2;
    }
};

ListNode *buildList(const vector<int> &arr) {
    auto dummy = ListNode();
    auto curser = &dummy;
    for (auto i: arr) {
        curser->next = new ListNode(i);
        curser = curser->next;
    }
    return dummy.next;
}

int main() {
    Solution().partition(buildList({1, 4, 3, 2, 5, 2}), 3);
    return 0;
}
