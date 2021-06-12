/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-12 09:00:55
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-12 11:18:03
 * @FilePath: \Leetcode\C++\0025-reverse-nodes-in-k-group.cpp
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {};
  ListNode(int x) : val(x), next(nullptr) {};
  ListNode(int x, ListNode* next) : val(x), next(next) {};
};

#include <cstdio>

using namespace std;

class Solution {
  public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr) return head;
    ListNode *a = head, *b = head;
    for(int i = 0; i < k; i++) {
      if(b == nullptr) return head;
      b = b->next;
    }
    // 翻转前K个元素
    ListNode *newHead = reverse(a, b);
    // 把翻转后的元素连接起来
    a->next = reverseKGroup(b, k);
    return newHead;
  }

  // 翻转区间在[start, end)之间的元素
  ListNode* reverse(ListNode* start, ListNode* end) {
    ListNode *pre = nullptr, *cur = start, *next = start;
    while(cur != end) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    // 返回翻转后的头结点
    return pre;
  }
};