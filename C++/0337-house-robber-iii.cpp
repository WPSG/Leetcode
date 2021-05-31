/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-05-31 20:53:30
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-31 22:00:24
 * @FilePath: \Leetcode\C++\0337-house-robber-iii.cpp
 */
#include <cstdio>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
  unordered_map<TreeNode* , int> umap; // 记录计算过的结果
  int rob(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->val;
    if (umap[root]) return umap[root]; // 如果umap里已经有记录则直接返回
    // 偷父节点
    int val1 = root->val;
    if (root->left) val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left
    if (root->right) val1 += rob(root->right->left) + rob(root->right->right); // 跳过root->right
    // 不偷父节点
    int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
    umap[root] = max(val1, val2); // umap记录一下结果
    return max(val1, val2);
  }
};