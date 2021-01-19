/*
 * @Date: 2021-01-19 14:40:48
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-19 15:26:30
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
};

int main(){
  vector<int> prices = {2,4,1};
  int res = (new Solution)->maxProfit(prices);
  printf("%d", res);
}