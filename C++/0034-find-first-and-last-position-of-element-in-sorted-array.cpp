/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-05-23 10:45:03
 * @LastEditors: ROC
 * @LastEditTime: 2021-05-23 14:39:01
 * @FilePath: \Leetcode\C++\0034-find-first-and-last-position-of-element-in-sorted-array.cpp
 */
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
      vector<int> res;
      int firstPos = getFirstPosition(nums, target);
      int lastPos = getLastPosition(nums, target);
      res.push_back(firstPos);
      res.push_back(lastPos);
      return res;
    }

    int getFirstPosition(vector<int> &nums, int target) {
      int left = 0, right = nums.size() - 1;
      while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
          right = mid - 1;
        } else if (nums[mid] < target) {
          left = mid + 1;
        } else if (nums[mid] == target) {
          right = mid - 1;
        }
      }
      if(left >= nums.size() || nums[left] != target) {
        return -1;
      }
      return left;
    }

    int getLastPosition(vector<int> &nums, int target) {
      int left = 0, right = nums.size() - 1;
      while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
          right = mid - 1;
        } else if (nums[mid] < target) {
          left = mid + 1;
        } else if (nums[mid] == target) {
          left = mid + 1;
        }
      }
      if(right < 0 || nums[right] != target) {
        return -1;
      }
      return right;
    }
};

