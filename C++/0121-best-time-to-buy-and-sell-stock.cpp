/*
 * @Date: 2021-01-19 14:40:48
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-25 21:01:07
 * @FilePath: \Leetcode\C++\0121-best-time-to-buy-and-sell-stock.cpp
 */
#include <cstdio>
#include <vector>
#include <limits.h>

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
      int dp_i_0 = 0, dp_i_1 = INT_MIN;
      // 新状态只和相邻的一个状态有关，其实不用整个 dp 数组，只需要一个变量储存相邻的那个状态就足够了，这样可以把空间复杂度降到 O(1)
      for(int i = 0; i < n; i++) {
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, -prices[i]);
      }
      return dp_i_0;
    }
};

int main(){
  vector<int> prices = {7,1,5,3,6,4};
  int res = (new Solution)->maxProfitDP(prices);
  printf("%d", res);
}