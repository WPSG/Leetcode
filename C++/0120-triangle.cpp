/*
 * @Date: 2021-01-17 15:35:42
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-17 16:15:36
 * @FilePath: \Leetcode\C++\0120-triangle.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
  public:
    int minimumTotal(vector<vector<int>> &triangle){
      int rows = triangle.size();
      // 没有第一行或者第一行为空时，返回0
      if(rows == 0 || triangle[0].size() == 0) return 0;
      int res = triangle[0][0];
      if(rows == 1) return res; // 仅有第一行且第一行不为空时，返回第一行元素
      // 从倒数第二行开始，将本行的元素修改成与下一行相邻元素和的最小值，逐行向上遍历，最后返回第一行元素。
      for(int i = rows - 2; i >= 0; i--){
        int columns = triangle[i].size();
        for(int j = 0; j < columns; j++){
          triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
      }
      return triangle[0][0];
    }
};

int main(){
  vector<vector<int>> triangle = {{1}};
  int res = (new Solution)->minimumTotal(triangle);
  printf("%d", res);
}
/* 给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 
+ 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

示例 1：
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

示例 2：
输入：triangle = [[-10]]
输出：-10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle */