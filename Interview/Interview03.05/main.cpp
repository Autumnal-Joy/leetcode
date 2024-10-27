#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class SortedStack {
    stack<int> st;
    stack<int> temp;

public:
    SortedStack() {}

    void push(int val) {
        if (st.empty() || val <= st.top()) {
            st.push(val);
        } else {
            while (!st.empty() && val > st.top()) {
                temp.push(st.top());
                st.pop();
            }
            st.push(val);
            while (!temp.empty()) {
                st.push(temp.top());
                temp.pop();
            }
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int peek() {
        return st.empty() ? -1 : st.top();
    }

    bool isEmpty() {
        return st.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

int main() {
    return 0;
}
