/*
 * @Date: 2021-01-07 14:06:15
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-07 15:01:20
 * @FilePath: \Leetcode\C++\0041-first-missing-positive.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  int firstMissingPositive(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int target = 1, n = nums.size();
    if(n == 0) return target;
    for(int i = 0; i < n; i++){
      if(nums[i] == target) 
        target++;
    }
    return target;
  }
  /* 
    int firstMissingPositive(vector<int> &nums){
      sort(nums.begin(), nums.end());
      int target = 1, n = nums.size(), pre = 0;
      if(n == 0) return 1;
      for(int i = 0; i < n; i++){
        if(nums[i] <= 0 || nums[i] == pre) continue;
        else if(nums[i] == target){
          pre = nums[i];
          target++;
        }else{
          return target;
        }
      }
      return target;
    }
   */
};

int main(){
  vector<int> nums = {1,1,2,2,2};
  int res = (new Solution)->firstMissingPositive(nums);
  printf("%d", res);
}
/* 
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
示例 1:
输入: [1,2,0]
输出: 3
示例 2:
输入: [3,4,-1,1]
输出: 2
示例 3:
输入: [7,8,9,11,12]
输出: 1
 
提示：
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
 */