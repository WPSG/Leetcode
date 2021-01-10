/*
 * @Date: 2021-01-10 15:01:22
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-10 15:43:57
 * @FilePath: \Leetcode\C++\0053-maximum-subarray.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
public:

  /**
   * @Description: 题目要求输出数组中某个区间内数字之和最大的那个值。res表示前面区间内各个子区间和的最大值，
   *    状态转移方程是 res = nums[i] + res (res > 0)，res = nums[i] (res ≤ 0)。
   * @Author: ROC
   * @param {vector<int> &nums}
   * @return {int res}
   */
  int maxSubArray(vector<int> & nums){
    int preMax = 0, res = nums[0], length = nums.size();
    if(length == 0) return 0;
    if(length == 1) return nums[0];
    for (int i = 0; i < length; i++){
      preMax = preMax > 0 ? (preMax + nums[i]) : nums[i];
      res = res > preMax ? res : preMax;
    }
    return res;
  }
};

int main(){
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  int res = 0;
  res = (new Solution)->maxSubArray(nums);
  printf("%d", res);
}

/* 
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
 */