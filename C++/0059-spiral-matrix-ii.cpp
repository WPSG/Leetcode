/*
 * @Date: 2021-01-12 15:57:00
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-12 16:19:47
 * @FilePath: \Leetcode\C++\0059-spiral-matrix-ii.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
public:
  /**
   * @Description: https://github.com/WPSG/Leetcode/blob/main/C%2B%2B/0054-spiral-matrix.cpp
   * @Author: ROC
   * @param {int n}
   * @return {vector<vector<int>>}
   */
  vector<vector<int>> generateMatrix(int n){
    int top = 0, bottom = n - 1, left = 0, right = n - 1, count = 0;
    vector<vector<int>> res(n, vector<int>(n));
    if(n == 0) return res;
    while(true){
      for(int i = left; i <= right; i++) res[top][i] = ++count;
      if(++top > bottom) break;
      for(int i = top; i <= bottom; i++) res[i][right] = ++count;
      if(--right < left) break;
      for(int i = right; i >= left; i--) res[bottom][i] = ++count;
      if(--bottom < top) break;
      for(int i = bottom; i >= top; i--) res[i][left] = ++count;
      if(++left > right) break;
    }
    return res;
  }
};

int main(){
  int n = 3;
  vector<vector<int>> res = (new Solution)->generateMatrix(n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}
/* 
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
 */