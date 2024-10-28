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
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        do {
            if (!fast || !fast->next) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};

int main() {

    return 0;
}
