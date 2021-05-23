/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-05-23 10:40:10
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-23 10:42:34
 * @FilePath: \Leetcode\C++\0704-binary-search.cpp
 */
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right) {
      int mid = left + (right - left) / 2;
      if(nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};