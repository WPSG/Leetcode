/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-12 13:40:02
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-12 15:04:13
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
  bool isPalindrome(ListNode* head) {
    // 通过「双指针技巧」中的快慢指针来找到链表的中点
    ListNode *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // 如果fast指针没有指向null，说明链表长度为奇数，slow还要再前进一步
    if(fast != NULL) {
      slow = slow->next;
    }
    // 从slow开始反转后面的链表，开始比较回文串
    ListNode* left = head;
    ListNode* right = reverse(slow);
    while(right != NULL) {
      if(left->val != right->val) return false;
      left = left->next;
      right = right->next;
    }
    return true;
  }

  // 翻转以head开头的链表，返回新链表的起始节点
  ListNode* reverse(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* last = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
  }
};