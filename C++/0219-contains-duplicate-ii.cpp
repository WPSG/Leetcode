/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-04-27 15:54:47
 * @LastEditors: ROC
 * @LastEditTime: 2021-04-27 16:25:59
 * @FilePath: \Leetcode\C++\0219-contains-duplicate-ii.cpp
 */
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++) {
          if(map.count(nums[i]) > 0 && i-map[nums[i]] <= k) {
            return true;
          }
          map[nums[i]] = i;
        }
        return false;
    }
};