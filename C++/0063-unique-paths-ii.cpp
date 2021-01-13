/*
 * @Date: 2021-01-13 15:00:36
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-13 15:58:35
 * @FilePath: \Leetcode\C++\0063-unique-paths-ii.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid){
    int rows = obstacleGrid.size(); // 行数
    if(rows == 0 || obstacleGrid[0][0] == 1) return 0; // 行数为0或(0,0)处有障碍物，返回0退出
    int columns = obstacleGrid[0].size(); // 列数
    vector<vector<int>> dp(rows,vector<int>(columns));
    dp[0][0] = 1;
    for(int i = 1; i < rows; i++) { // 只有上一行不是障碍物并且此行不是障碍物时为1
      if(dp[i - 1][0] == 1 && obstacleGrid[i][0] != 1) dp[i][0] = 1;
    }
    for(int i = 1; i < columns; i++) { // 前一列不是障碍物并且此列不是障碍物时为1
      if(dp[0][i - 1] == 1 && obstacleGrid[0][i] != 1) dp[0][i] = 1;
    }
    for(int i = 1; i < rows; i++){
      for(int j = 1; j < columns; j++){
        if(obstacleGrid[i][j] != 1) // 跳过障碍物
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[rows - 1][columns - 1];
  }
};

int main(){
  vector<vector<int>> obstacleGrid = {};
  int res = (new Solution)->uniquePathsWithObstacles(obstacleGrid);
  printf("%d", res);
}

/* 
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。

示例 1：
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

示例 2：
输入：obstacleGrid = [[0,1],[0,0]]
输出：1
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
 */