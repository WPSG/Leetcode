/*
 * @Date: 2021-01-13 14:13:01
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-13 14:53:48
 * @FilePath: \Leetcode\C++\0062-unique-paths.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
public:
  /**
   * @Description: ——DP
   *  用dp[i][j]表示从左上角走到（i,j）的路径数量。由于我们每一步只能从向下或者向右移动一步，因此要想走到（i,j）
   *  如果向下走一步，那么会从 (i−1,j)(i-1, j)(i−1,j) 走过来；如果向右走一步，那么会从 (i,j−1)(i, j-1)(i,j−1) 走过来。
   *  所以地图中任意一点的走法数是 dp[i][j] = dp[i-1][j] + dp[i][j-1]
   * @Author: ROC
   * @param {int} m
   * @param {int} n
   * @return {*}
   */
  int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n));
    for(int i = 0; i < m; i++) dp[i][0] = 1;
    for(int i = 0; i < n; i++) dp[0][i] = 1;
    for(int i = 1; i < m; i++){
      for(int j = 1; j < n; j++){
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(){
  int m = 3, n = 7, res = 0;
  res = (new Solution)->uniquePaths(m ,n);
  printf("%d", res);
}

/* 
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？

示例 1：
输入：m = 3, n = 7
输出：28
示例 2：
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 3：
输入：m = 7, n = 3
输出：28
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
 */