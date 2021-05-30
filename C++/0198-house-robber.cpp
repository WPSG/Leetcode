/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-05-30 21:00:48
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-30 21:36:57
 * @FilePath: \Leetcode\C++\0198-house-robber.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
  public:
  int rob(vector<int>& nums) {
    if(nums.empty()) return 0;
    int n = nums.size();
    if(n == 1) return nums[0];
    // vector<int> dp = vector<int>(n, 0);
    int first = nums[0];
    int second = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      int temp = second;
      second = max(first + nums[i], second);
      first = temp;
    }
    return second;
  }
};

int main() {
  vector<int> nums = {2,7,9,3,1};
  int res = (new Solution)->rob(nums);
  printf("%d\n", res);
  return res;
}