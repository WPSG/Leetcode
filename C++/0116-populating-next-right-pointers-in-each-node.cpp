/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-08 19:30:42
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-08 19:40:45
 * @FilePath: \Leetcode\C++\0116-populating-next-right-pointers-in-each-node.cpp
 */
#include <cstdio>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
  Node* connect(Node* root) {
    if(root == NULL) return NULL;
    connectHelper(root->left, root->right);
    return root;
  }

  void connectHelper(Node* node1, Node* node2) {
    if(node1 == NULL || node2 == NULL) return;
    // 将传入的两个节点相连
    node1->next = node2;
    // 连接相同父节点的两个节点
    connectHelper(node1->left, node1->right);
    connectHelper(node2->left, node2->right);
    // 连接不同父节点的两个节点
    connectHelper(node1->right, node2->left);
  }
};