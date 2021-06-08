/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-08 19:17:05
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-08 19:27:42
 * @FilePath: \Leetcode\C++\0226-invert-binary-tree.cpp
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <cstdio>

using namespace std;

class Solution {
  public:
  TreeNode* invertTree(TreeNode* root) {
    // base case
    if(root == NULL) return NULL;
    // root节点需要调换他的左右子节点
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // 让左右子节点继续翻转他们的子节点
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
  }
};