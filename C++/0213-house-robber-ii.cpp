/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-05-31 19:37:06
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-31 20:37:44
 * @FilePath: \Leetcode\C++\0213-house-robber-ii.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
  public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    return max(maxProfit(nums, 0, n - 2), maxProfit(nums, 1, n - 1));
  }
  int maxProfit(vector<int>& nums, int start, int end) {
    int first = 0, second = 0, temp = 0;
    for(int i = start; i <= end; i++) {
      temp = second;
      second = max(first + nums[i], second);
      first = temp;
    }
    return second;
  }
};

int main() {
  vector<int> nums = {1,2,3,1};
  int res = (new Solution) -> rob(nums);
  printf("%d\n", res);
  return res;
}