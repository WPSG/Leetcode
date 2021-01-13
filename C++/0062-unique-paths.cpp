/*
 * @Date: 2021-01-13 14:13:01
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-13 14:36:29
 * @FilePath: \Leetcode\C++\0062-unique-paths.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
public:
  int uniquePaths(int m, int n){
    unsigned long long int temp = 1;
    unsigned long long int result = 1;
    if (m == 1 || n == 1) return 1;
    if (m > n) swap(m, n); //保证m<=n
    //计算阶乘
    for (int i = 1; i <= m-1 ; i++){
      temp *= i;
    }
    for (int i = n; i <= m + n - 2; i++){
      result *= i;
    }
    result = result / temp;
    return result;
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