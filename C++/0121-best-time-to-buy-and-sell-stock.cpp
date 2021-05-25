/*
 * @Date: 2021-01-19 14:40:48
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-25 20:33:26
 * @FilePath: \Leetcode\C++\0121-best-time-to-buy-and-sell-stock.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices){
      if(prices.size() <= 1) return 0;
      int minPrice = prices[0], max = 0;
      for(int i = 1; i < prices.size(); i++){
        if(prices[i] - minPrice > max){
          max = prices[i] - minPrice;
        }
        if(prices[i] < minPrice){
          minPrice = prices[i];
        }
      }
      return max;
    }

    int maxProfitDP(vector<int> &prices) {
      int n = prices.size();
      // dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
      // dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]) 
      //             = max(dp[i-1][1][1], -prices[i])
      // 解释：k = 0 的 base case，所以 dp[i-1][0][0] = 0。
      // 现在发现 k 都是 1，不会改变，即 k 对状态转移已经没有影响了。
      // 可以进行进一步化简去掉所有 k：
      // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
      // dp[i][1] = max(dp[i-1][1], -prices[i])
      int (*dp)[2] = new int[n][2];
      for(int i = 0; i < n; i++) {
        if(i == 0) {
          dp[i][0] = 0;
          dp[i][1] = -prices[i];
          continue;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
      }
      return dp[n - 1][0];
    }
};

int main(){
  vector<int> prices = {7,1,5,3,6,4};
  int res = (new Solution)->maxProfitDP(prices);
  printf("%d", res);
}