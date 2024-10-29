#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Checkout {
    deque<shared_ptr<int>> q;
    deque<shared_ptr<int>> dec_q;

public:
    Checkout() = default;

    int get_max() const {
        return !dec_q.empty() ? *dec_q.front() : -1;
    }

    void add(const int value) {
        const auto &ptr = std::make_shared<int>(value);
        q.push_back(ptr);
        while (!dec_q.empty() && *dec_q.back() < value) {
            dec_q.pop_back();
        }
        dec_q.push_back(ptr);
    }

    int remove() {
        if (q.empty()) {
            return -1;
        }
        if (dec_q.front() == q.front()) {
            dec_q.pop_front();
        }
        const auto res = *q.front();
        q.pop_front();
        return res;
    }
};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
