/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-13 10:32:19
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-13 15:38:37
 * @FilePath: \Leetcode\C++\0652-find-duplicate-subtrees.cpp
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
  public:
  unordered_map<string, int> memo;
  vector<TreeNode*> res;

  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    helper(root);
    return res;
  }

  string helper(TreeNode* root) {
    if (root == nullptr) return "#";
    string left = helper(root->left);
    string right = helper(root->right);
    string subString  = left + "," + right+ "," + to_string(root->val);
    int freq = memo[subString];
    if(freq == 1) res.push_back(root);
    memo[subString] = freq + 1;
    return subString;
  }
};