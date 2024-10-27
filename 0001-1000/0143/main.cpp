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
    void reorderList(ListNode *head) {
        int n = 0;
        auto temp = head;
        while (temp) {
            ++n;
            temp = temp->next;
        }
        if (n <= 2) return;
        auto mid = head;
        for (int i = 0; i < n / 2; ++i) {
            mid = mid->next;
        }
        auto st = stack<ListNode *>();
        temp = mid->next;
        mid->next = nullptr;
        while (temp) {
            st.push(temp);
            temp = temp->next;
        }
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            top->next = head->next;
            head->next = top;
            head = top->next;
        }
    }
};

int main() {

    return 0;
}
