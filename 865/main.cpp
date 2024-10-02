#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  TreeNode *res;
  int getDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + max(getDepth(root->left), getDepth(root->right));
  }
  bool hasDeep(TreeNode *root, int depth, int maxDepth) {
    if (root == nullptr) {
      if (depth == maxDepth) {
        return true;
      } else {
        return false;
      }
    }
    bool hasDeepLeft = hasDeep(root->left, depth + 1, maxDepth);
    bool hasDeepRight = hasDeep(root->right, depth + 1, maxDepth);
    if (hasDeepLeft && hasDeepRight) {
      res = root;
      return true;
    }
    if (hasDeepLeft || hasDeepRight) {
      return true;
    }
    return false;
  }

public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    auto depth = getDepth(root);
    hasDeep(root, 0, depth);
    return res;
  }
};

int main() {

  auto root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  auto s = Solution();
  auto res = s.subtreeWithAllDeepest(root);
  return 0;
}
