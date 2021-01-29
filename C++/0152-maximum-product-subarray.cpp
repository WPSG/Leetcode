/*
 * @Author: ROC
 * @Date: 2021-01-29 14:06:42
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-29 14:32:10
 * @FilePath: \Leetcode\C++\0152-maximum-product-subarray.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
  public:
    int maxProduct(vector<int> &nums){
      int length = nums.size();
      if(length == 0) return 0;
      int temp, minNums = nums[0], maxNums = nums[0], res = nums[0];
      for(int i = 1; i < length; i++){
        if(nums[i] < 0){
          temp = maxNums;
          maxNums = minNums;
          minNums = temp;
        }
        maxNums = max(maxNums * nums[i], nums[i]);
        minNums = min(minNums * nums[i], nums[i]);
        res = max(maxNums, res);
      }
      return res;
    }
};

int main(){
  vector<int> nums = {2,3,-2,4};
  int res = (new Solution)->maxProduct(nums);
  printf("%d", res);
}