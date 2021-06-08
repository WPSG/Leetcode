/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-08 19:45:44
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-08 19:55:19
 * @FilePath: \Leetcode\C++\0114-flatten-binary-tree-to-linked-list.cpp
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <cstdio>

using namespace std;

class Solution {
  public:
  void flatten(TreeNode* root) {
    // base case
    if(root == NULL) return;
    flatten(root->left);
    flatten(root->right);
    // 左右子树已经被拉成一条直线
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    // 将左子树作为右子树
    root->left = NULL;
    root->right = left;
    // 将原有的右子树接到当前右子树的末尾
    TreeNode* p = root;
    while(p->right != NULL) p = p->right;
    p->right = right;
  }
};