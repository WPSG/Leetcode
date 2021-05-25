/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-05-25 21:44:26
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-25 22:06:06
 * @FilePath: \Leetcode\C++\0309-best-time-to-buy-and-sell-stock-with-cooldown.cpp
 */

#include <cstdio>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    // 这题和之前的 0121 和 0122 相同，k 还是无限大，只是在交易的时候设置了一个冷静期(隔一天进行交易)，所以在写状态转移方程的时候添上就行
    int n = prices.size();
    // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
    // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 2][k - 1][0] - prices[i])
    // k 为无限大，且第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。所以化简为：
    // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
    // dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i])
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    int dp_i2_0 = 0;
    for(int i = 0; i < n; i++) {
      int pre = dp_i_0;
      dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
      dp_i_1 = max(dp_i_1, dp_i2_0 - prices[i]);
      dp_i2_0 = pre;
    }
    return dp_i_0;
  }
};

int main() {
  vector<int> prices = {1,2,3,0,2};
  int res = (new Solution)->maxProfit(prices);
  printf("%d", res);
}