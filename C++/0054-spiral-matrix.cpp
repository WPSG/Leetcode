/*
 * @Date: 2021-01-11 13:47:26
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-11 14:43:50
 * @FilePath: \Leetcode\C++\054-spiral-matrix.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
public:
  /**
   * @Description: 
   *  首先设定上下左右边界
      其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
      判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
      若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
      不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
   * @Author: ROC
   * @param {vector<vector<int>> &matrix}
   * @return {vector<int>}
   */
  vector<int> spiralOrder(vector<vector<int>> &matrix){
    vector<int> res;
    int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    if(matrix.empty()) return res; // 若数组为空，则返回
    while(true){
      for(int i = left; i <= right; i++) // 向右移动
        res.push_back(matrix[top][i]);
      if(++top > bottom) break; // 上下交替，完成退出
      for(int i = top; i <= bottom; i++) // 向下移动
        res.push_back(matrix[i][right]);
      if(--right < left) break; // 左右交替，退出
      for(int i = right; i >= left; i--) // 向左移动
        res.push_back(matrix[bottom][i]);
      if(--bottom < top) break; // 上下交替，退出
      for(int i = bottom; i >= top; i--)// 向上移动
        res.push_back(matrix[i][left]);
      if(++left > right) break;// 左右交替，退出
    }
    return res;
  }
};

int main(){
  vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
  vector<int> res = (new Solution)->spiralOrder(matrix);
  int length  = res.size();
  for(int i = 0; i < length; i++){
    printf("%d ", res[i]);
  }
}
/* 
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
示例 1:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
 */