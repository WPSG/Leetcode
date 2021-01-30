/*
 * @Author: ROC
 * @Date: 2021-01-29 15:15:27
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-30 15:56:46
 * @FilePath: \Leetcode\C++\0209-minimum-size-subarray-sum.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
  public:
    int minSubArrayLen(int s, vector<int> &nums){
      int leftPos = 0, rightPos = -1, sum = 0, length = nums.size();
      int res = length + 1;
      if(length == 0) return 0;
      while(leftPos < length){
        if(rightPos + 1 < length && sum < s){
          sum += nums[++rightPos];
        } else {
          sum -= nums[leftPos++];
        }
        if(sum >= s){
          res = min(res, rightPos - leftPos + 1);
        }
      }
      if(res == length + 1)
        return 0;
      return res;
    }
};

int main(){
  vector<int> nums = {2,3,1,2,4,3};
  int s = 7;
  int res = (new Solution)->minSubArrayLen(s, nums);
  printf("%d", res);
}