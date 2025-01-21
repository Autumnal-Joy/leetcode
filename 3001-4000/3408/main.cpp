#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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

class TaskManager {
    priority_queue<tuple<int, int, int>> pq;
    unordered_map<int, tuple<int, int, int>> taskList;

public:
    TaskManager(const vector<vector<int>> &tasks) {
        for (const auto &task: tasks) {
            pq.emplace(task[2], task[1], task[0]);
            taskList[task[1]] = {task[2], task[1], task[0]};
        }
    }

    void add(int userId, int taskId, int priority) {
        pq.emplace(priority, taskId, userId);
        taskList[taskId] = {priority, taskId, userId};
    }

    void edit(int taskId, int newPriority) {
        auto &task = taskList[taskId];
        std::get<0>(task) = newPriority;
        pq.push(task);
    }

    void rmv(const int taskId) {
        taskList.erase(taskId);
    }

    int execTop() {
        while (true) {
            if (pq.empty()) {
                return -1;
            }
            auto [priority, taskId, userId] = pq.top();
            pq.pop();
            if (taskList.contains(taskId) && std::get<0>(taskList[taskId]) == priority) {
                taskList.erase(taskId);
                return userId;
            }
        }
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
#ifdef LEETCODE
int main() {
    auto tasks = vector<vector<int>>({{10, 26, 25}});
    TaskManager *obj = new TaskManager(tasks);
    obj->rmv(26);
    int param_4 = obj->execTop();
    return 0;
}
#endif
