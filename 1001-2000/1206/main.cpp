#include <bits/stdc++.h>

#ifdef LOCAL
#include "lc_structures.h"
#include "log.h"
#else
#define dbg(x...) (x)
#endif

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

template<class T>
using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;

constexpr int MAX_I = 0x3f3f3f3f;
constexpr int MIN_I = -MAX_I;
constexpr int MOD = 1e9 + 7;
constexpr ll MAX_LL = 0x3f3f3f3f'3f3f3f3f;
constexpr ll MIN_LL = -MAX_LL;
constexpr double EPS = 1e-8;

TreeNode *vec2tree(const std::vector<int> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    auto *root = new TreeNode(vec[0]);
    auto q = std::queue<TreeNode *>();
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        const auto node = q.front();
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

ListNode *vec2list(const std::vector<int> &vec) {
    ListNode head;
    ListNode *p = &head;
    for (const auto &val: vec) {
        p->next = new ListNode(val);
        p = p->next;
    }
    return head.next;
}

vector<vector<int>> read2d(const string &filename) {
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
void write1d(const vector<int> &data, const string &filename) {
    auto ofs = ofstream(filename);
    std::copy(data.begin(), data.end(), ostream_iterator<int>(ofs, " "));
    ofs << '\n';
}
void write2d(const vector<vector<int>> &data, const string &filename) {
    auto ofs = ofstream(filename);
    for (const auto &line: data) {
        std::copy(line.begin(), line.end(), ostream_iterator<int>(ofs, " "));
        ofs << '\n';
    }
}

template<typename T, size_t N, size_t... Ns>
auto Array() {
    if constexpr (sizeof...(Ns) == 0) {
        return array<T, N>{};
    } else {
        return array<decltype(Array<T, Ns...>()), N>{};
    }
}

template<typename T>
struct is_nd_array : std::false_type {};

template<typename T, size_t N>
struct is_nd_array<array<T, N>> : std::true_type {};

template<typename T, typename V>
void fillArray(T &arr, const V &val) {
    if constexpr (is_nd_array<T>::value) {
        for (auto &elem: arr) {
            fillArray(elem, val);
        }
    } else {
        arr = val;
    }
}

class Skiplist {
    constexpr static int MAX_LEVEL = 16;

    struct Node {
        int key;
        vector<Node *> forward;
        Node(const int key, const int level, Node *next = nullptr) : key(key) {
            forward = vector(level, next);
        }
    };
    static bool random_bool() {
        static std::mt19937 engine(std::random_device{}());
        static std::bernoulli_distribution dist(0.5);// 50% 概率
        return dist(engine);
    }
    static int randLevel() {
        int level = 1;
        while (random_bool() && level < MAX_LEVEL) {
            ++level;
        }
        return level;
    }

    Node *head, *tail = nullptr;

public:
    Skiplist() {
        tail = new Node(MAX_I, 0);
        head = new Node(MIN_I, MAX_LEVEL, tail);
    }
    ~Skiplist() {
        delete head;
        delete tail;
    }

    bool search(const int key) const {
        auto cur = head;
        for (int level = MAX_LEVEL - 1; level >= 0; --level) {
            while (cur->forward[level]->key < key) {
                cur = cur->forward[level];
            }
        }
        return cur->forward[0]->key == key;
    }

    void add(const int key) const {
        auto update = vector(MAX_LEVEL, head);
        auto cur = head;
        for (int level = MAX_LEVEL - 1; level >= 0; --level) {
            while (cur->forward[level]->key < key) {
                cur = cur->forward[level];
            }
            update[level] = cur;
        }
        const int level = randLevel();
        const auto node = new Node(key, level);
        for (int i = 0; i < level; ++i) {
            node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = node;
        }
    }

    bool erase(const int key) const {
        auto update = vector(MAX_LEVEL, head);
        auto cur = head;
        for (int level = MAX_LEVEL - 1; level >= 0; --level) {
            while (cur->forward[level]->key < key) {
                cur = cur->forward[level];
            }
            update[level] = cur;
        }
        const auto node = cur->forward[0];
        if (node->key != key) {
            return false;
        }
        for (int i = 0; i < node->forward.size(); ++i) {
            update[i]->forward[i] = node->forward[i];
        }
        delete node;
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

#ifdef LOCAL

int main() {
    const auto sl = new Skiplist();
    sl->add(1);
    sl->add(2);
    sl->add(3);
    dbg(sl->search(0));
    sl->add(4);
    dbg(sl->search(1));
    dbg(sl->erase(0));
    dbg(sl->erase(1));
    dbg(sl->search(1));
    delete sl;
}
#endif
