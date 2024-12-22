#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#ifdef LEETCODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *vec2tree(const vector<int> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    auto *root = new TreeNode(vec[0]);
    auto q = queue<TreeNode *>();
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        auto node = q.front();
        q.pop();
        if (vec[i] != -1) {
            node->left = new TreeNode(vec[i]);
            q.push(node->left);
        }
        if (i + 1 < vec.size() && vec[i + 1] != -1) {
            node->right = new TreeNode(vec[i + 1]);
            q.push(node->right);
        }
    }
    return root;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};
ListNode *vec2list(const vector<int> &vec) {
    ListNode head;
    ListNode *p = &head;
    for (const auto &val: vec) {
        p->next = new ListNode(val);
        p = p->next;
    }
    return head.next;
}
vector<vector<int>> read(const string &filename) {
    auto res = vector<vector<int>>();
    auto ifs = ifstream(filename);
    auto line = string();
    while (getline(ifs, line)) {
        auto vec = vector<int>();
        auto iss = istringstream(line);
        for (int val; iss >> val;) {
            vec.push_back(val);
        }
        res.push_back(std::move(vec));
    }
    return res;
}
void write(const vector<int> &data, const string &filename) {
    auto ofs = ofstream(filename);
    ranges::copy(data, ostream_iterator<int>(ofs, " "));
    ofs << '\n';
}
void write(const vector<vector<int>> &data, const string &filename) {
    auto ofs = ofstream(filename);
    for (const auto &line: data) {
        ranges::copy(line, ostream_iterator<int>(ofs, " "));
        ofs << '\n';
    }
}
#endif

struct Comp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
        const auto d1 = p1.second - p1.first, d2 = p2.second - p2.first;
        return d1 / 2 == d2 / 2 ? p1.first > p2.first : d1 / 2 < d2 / 2;
    }
};

class ExamRoom {
    int n;
    set<int> seats;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

public:
    explicit ExamRoom(const int n) : n(n) {}

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        const auto left = *seats.begin(), right = n - 1 - *seats.rbegin();

        if (seats.size() >= 2) {
            for (auto [fst, sec] = pq.top();
                 !seats.contains(fst) || !seats.contains(sec) || *next(seats.find(fst)) != sec;
                 std::tie(fst, sec) = pq.top()) {
                pq.pop();
            }

            const auto [fst, sec] = pq.top();
            const auto len = sec - fst;
            if (len / 2 >= right && len / 2 > left) {
                pq.pop();
                const auto mid = fst + len / 2;
                seats.insert(mid);
                pq.emplace(fst, mid);
                pq.emplace(mid, sec);
                return mid;
            }
        }

        if (right > left) {
            pq.emplace(*seats.rbegin(), n - 1);
            seats.insert(n - 1);
            return n - 1;
        } else {
            pq.emplace(0, *seats.begin());
            seats.insert(0);
            return 0;
        }
    }

    void leave(const int p) {
        if (p != *seats.begin() && p != *seats.rbegin()) {
            const auto it = seats.find(p);
            pq.emplace(*prev(it), *next(it));
        }
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

#ifdef LEETCODE
int main() {
    auto er = ExamRoom(10);
    cout << er.seat() << endl;
    cout << er.seat() << endl;
    cout << er.seat() << endl;
    cout << er.seat() << endl;
    er.leave(4);
    cout << er.seat() << endl;
    return 0;
}
#endif
