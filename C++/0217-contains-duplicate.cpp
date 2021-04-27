/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-04-27 15:37:26
 * @LastEditors: ROC
 * @LastEditTime: 2021-04-27 15:49:49
 * @FilePath: \Leetcode\C++\0217-contains-duplicate.cpp
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
          return true;
        }
      }
      return false;
    }
};

int main() {
  vector<int> nums = {5,8,4,6,9,7,8,1,8,9};
  printf("%d", (new Solution)->containsDuplicate(nums));
}