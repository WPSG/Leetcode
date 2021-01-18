/*
 * @Date: 2021-01-18 15:57:13
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-18 16:48:30
 * @FilePath: \Leetcode\C++\0106-construct-binary-tree-from-inorder-and-postorder-traversal.cpp
 */
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
  public:
    TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, int inorder_left, 
                          int inorder_right, int postorder_left, int postorder_right, unordered_map<int, int> &index){
      if(inorder_left > inorder_right) return nullptr;
      int postorder_root = postorder_right;
      int inorder_root = index[postorder[postorder_root]];

      TreeNode* root = new TreeNode(postorder[postorder_root]);

      int subRightTreeLength = inorder_right - inorder_root;
      root->right = myBuildTree(inorder, postorder, inorder_root + 1, inorder_right, postorder_right - subRightTreeLength, postorder_right - 1, index);
      root->left = myBuildTree(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_right - subRightTreeLength - 1, index);
      return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n = postorder.size();
      unordered_map<int, int> index;
      for(int i = n - 1; i >= 0; i--){
        index[inorder[i]] = i;
      }
      return myBuildTree(inorder, postorder, 0, n - 1, 0, n - 1, index);
    }
};

int main(){
  vector<int> inorder = {9,3,15,20,7};
  vector<int> postorder = {9,15,7,20,3};
  TreeNode *root = (new Solution)->buildTree(inorder, postorder);
  while(root){
    printf("%d ", root->val);
    root = root->right;
  }
}