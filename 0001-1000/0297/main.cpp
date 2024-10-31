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

#ifdef LEETCODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Codec {
    static string join(const vector<string> &vec, const char delimiter = ',') {
        if (vec.empty()) {
            return "";
        }
        string result = vec[0];
        for (int i = 1; i < vec.size(); ++i) {
            result += delimiter + vec[i];
        }
        return result;
    }
    static vector<string> split(const string &str, const char delimiter = ',') {
        vector<string> tokens;
        istringstream iss(str);
        string token;
        while (std::getline(iss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

public:
    // Encodes a tree to a single string.
    static string serialize(TreeNode *root) {
        function<void(const TreeNode *, vector<string> &)> preorder = [&](const TreeNode *node, vector<string> &list) {
            if (node == nullptr) {
                list.emplace_back("null");
                return;
            }
            list.push_back(to_string(node->val));
            preorder(node->left, list);
            preorder(node->right, list);
        };
        auto list = vector<string>();
        preorder(root, list);
        return join(list);
    }

    // Decodes your encoded data to tree.
    static TreeNode *deserialize(const string &data) {
        int i = 0;
        function<TreeNode *(const vector<string> &)> preorder = [&](const vector<string> &list) -> TreeNode * {
            TreeNode *res = nullptr;
            if (list[i++] != "null") {
                res = new TreeNode(stoi(list[i - 1]));
                res->left = preorder(list);
                res->right = preorder(list);
            }
            return res;
        };
        const auto list = split(data);
        const auto root = preorder(list);
        return root;
    }
};

#ifdef LEETCODE
int main() {
    auto codec = Codec();
    auto tree = Codec::deserialize("1,2,null,null,3,null,null");
    return 0;
}
#endif
