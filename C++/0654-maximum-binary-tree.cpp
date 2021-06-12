/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-12 16:51:02
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-13 07:55:35
 * @FilePath: \Leetcode\C++\0654-maximum-binary-tree.cpp
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
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
  public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructHelper(nums, 0, nums.size() - 1);
  }
  // 将nums[start, end]构造成符合条件的树
  TreeNode* constructHelper(vector<int>& nums, int start, int end) {
    if(start > end) return NULL;
    int index = -1, maxNum = INT_MIN;
    // 找到最大值与他的索引
    for(int i = start; i <= end; i++) {
      if(nums[i] > maxNum) {
        index = i;
        maxNum = nums[i];
      }
    }
    TreeNode *root = new TreeNode(maxNum);
    // 递归的构造左右子树
    root->left = constructHelper(nums, start, index - 1);
    root->right = constructHelper(nums, index + 1, end);
    return root;
  }
};