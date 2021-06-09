/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-08 21:17:08
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-09 21:11:10
 * @FilePath: \Leetcode\C++\0092-reverse-linked-list-ii.cpp
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
}

#include <cstdio>

using namespace std;

class Solution {
  public:
  ListNode* successor = nullptr; // 后驱节点
  // 反转以 head 为起点的 n 个节点，返回新的头结点
  ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) { 
      // 记录第 n + 1 个节点
      successor = head->next;
      return head;
    }
    // 以 head.next 为起点，需要反转前 n - 1 个节点
    ListNode* last = reverseN(head->next, n - 1);
    head->next->next = head;
    // 让反转之后的 head 节点和后面的节点连起来
    head->next = successor;
    return last;
  }

  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // base case
    if (left== 1) return reverseN(head, right);
    // 前进到反转的起点触发 base case
    head->next = reverseBetween(head->next, left - 1, right - 1);
    return head;
  }
};