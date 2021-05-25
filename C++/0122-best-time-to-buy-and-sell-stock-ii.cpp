/*
 * @Date: 2021-01-19 15:28:06
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-25 21:28:20
 * @FilePath: \Leetcode\C++\0122-best-time-to-buy-and-sell-stock-ii.cpp
 */
#include <cstdio>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int profit = 0, length = prices.size();
    for(int i = 0; i < length - 1; i++){
      if(prices[i + 1] > prices[i])
        profit += prices[i + 1] - prices[i];
    }
    return profit;
  }

  int maxProfitDP(vector<int> &prices) {
    int n = prices.size();
    // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
    // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
    // k 是无限大，所以 k-1 也为无限大，化简为：
    // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
    // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for(int i = 0; i < n; i++) {
      int pre = dp_i_0;
      dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
      dp_i_1 = max(dp_i_1, pre - prices[i]);
    }
    return dp_i_0;
  }
};

int main(){
  vector<int> prices = {7,1,5,3,6,4};
  int res = (new Solution)->maxProfitDP(prices);
  printf("%d", res);
}