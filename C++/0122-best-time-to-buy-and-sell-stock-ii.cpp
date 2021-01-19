/*
 * @Date: 2021-01-19 15:28:06
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-19 16:23:27
 * @FilePath: \Leetcode\C++\0122-best-time-to-buy-and-sell-stock-ii.cpp
 */
#include <cstdio>
#include <vector>

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
};

int main(){
  vector<int> prices = {7,1,5,3,6,4};
  int res = (new Solution)->maxProfit(prices);
  printf("%d", res);
}