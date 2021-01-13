/*
 * @Date: 2021-01-13 16:10:19
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-13 16:40:37
 * @FilePath: \Leetcode\C++\0064-minimum-path-sum.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  int minPathSum(vector<vector<int>> &grid){
    if(grid.size() == 0) return 0;
    int rows = grid.size(), columns = grid[0].size();
    for(int i = 1; i < rows; i++){
      grid[i][0] += grid[i - 1][0];
    }
    for(int i = 1; i < columns; i++){
      grid[0][i] += grid[0][i - 1];
    }
    for(int i = 1; i < rows; i++){
      for(int j = 1; j < columns; j++){
        grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
      }
    }
    return grid[rows - 1][columns - 1];
  }
};

int main(){
  vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
  int res = (new Solution)->minPathSum(grid);
  printf("%d", res);
}
/* 
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
 */