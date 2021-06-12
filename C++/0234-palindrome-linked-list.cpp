/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-12 13:40:02
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-12 14:19:00
 * @FilePath: \Leetcode\C++\0234-palindrome-linked-list.cpp
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode* next): val(x), next(next) {}
};

#include <cstdio>

using namespace std;

class Solution {
  public:

  ListNode* left = nullptr;

  bool isPalindrome(ListNode* head) {
    left = head;
    return traverse(head);
  }

  bool traverse(ListNode* right) {
    if(right == nullptr) return true;
    bool res = traverse(right->next);
    // 后序遍历链表
    res = res && (right->val == left->val);
    left = left->next;
    return res;
  }
};