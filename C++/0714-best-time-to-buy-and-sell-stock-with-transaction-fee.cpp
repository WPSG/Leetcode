/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-05-27 19:49:47
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-27 20:31:14
 * @FilePath: \Leetcode\C++\0714-best-time-to-buy-and-sell-stock-with-transaction-fee.cpp
 */
#include <cstdio>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
  public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
    // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i] - fee)
    // 因为k是无限大，所以可以化简为：
    // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for(int i = 0; i < n; i++) {
      int pre = dp_i_0;
      dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
      dp_i_1 = max(dp_i_1, pre - prices[i] - fee);
    }
    return dp_i_0;
  }
};

int main() {
  vector<int> prices = {1,3,2,8,4,9};
  int fee = 2;
  int res = (new Solution)->maxProfit(prices, fee);
  printf("%d\n", res);
  return res;
}