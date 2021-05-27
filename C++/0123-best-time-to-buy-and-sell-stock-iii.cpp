/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-05-27 20:35:13
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-27 22:49:47
 * @FilePath: \Leetcode\C++\0123-\best-time-to-buy-and-sell-stock-iii.cpp
 */
#include <cstdio>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
  public:
  int maxProfit(vector<int>& prices) {
  // 原始的动态转移方程，没有可化简的地方
  // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
  // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
  // 这道题由于没有消掉 k 的影响，所以必须要对 k 进行穷举
    int n = prices.size();
    int dp_i10 = 0, dp_i11 = INT_MIN;
    int dp_i20 = 0, dp_i21 = INT_MIN;
    for (int i = 0; i < n; i++) {
      dp_i20 = max(dp_i20, dp_i21 + prices[i]);
      dp_i21 = max(dp_i21, dp_i10 - prices[i]);
      dp_i10 = max(dp_i10, dp_i11 + prices[i]);
      dp_i11 = max(dp_i11, -prices[i]);
    }
    return dp_i20;
  }
};

int main() {
  vector<int> prices = {3,3,5,0,0,3,1,4};
  int res = (new Solution)->maxProfit(prices);
  printf("%d\n", res);
  return res;
}