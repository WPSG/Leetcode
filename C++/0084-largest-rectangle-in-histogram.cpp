/*
 * @Date: 2021-01-16 15:05:54
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-17 14:04:43
 * @FilePath: \Leetcode\C++\0084-largest-rectangle-in-histogram.cpp
 */
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

class Solution{
  public:
    int largestRectangleArea(vector<int> &heights){
      int n = heights.size();
      vector<int> left(n), right(n);
      stack<int> mono_stack;
      for (int i = 0; i < n; ++i) {
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
            mono_stack.pop();
        }
        left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
        mono_stack.push(i);
      }

      mono_stack = stack<int>();
      for (int i = n - 1; i >= 0; --i) {
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
            mono_stack.pop();
        }
        right[i] = (mono_stack.empty() ? n : mono_stack.top());
        mono_stack.push(i);
      }
      
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
      }
      return ans;
    }
};
int main(){
  vector<int> heights = {2,1,5,6,2,3};
  int res = (new Solution)->largestRectangleArea(heights);
  printf("%d", res);
}
/* 
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
 
示例:

输入: [2,1,5,6,2,3]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
 */