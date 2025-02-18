//
// Created by Autumnal Joy on 2025/2/18.
//
#include <bits/stdc++.h>

#ifndef LC_STRUCTURES_H
#define LC_STRUCTURES_H

#ifndef TREE_NODE
#define TREE_NODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x = 0) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(const int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

#ifndef LIST_NODE
#define LIST_NODE
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};
#endif

#endif //LC_STRUCTURES_H
