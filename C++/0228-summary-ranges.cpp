/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-04-29 15:35:19
 * @LastEditors: ROC
 * @LastEditTime: 2021-04-29 19:44:46
 * @FilePath: \Leetcode\C++\0228-summary-ranges.cpp
 */
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> res;
      int left = 0;
      for(int i = 0; i < nums.size(); i++) {
        if(i + 1 == nums.size() || nums[i] + 1 != nums[i + 1]) {
          string item = std::to_string(nums[left]) + (left == i ? "" : "->" + std::to_string(nums[i]));
          res.push_back(item);
          left = i + 1;
        }
      }
      return res;
    }
};

int main() {
  vector<int> nums = {0,1,2,4,5,7};
  vector<string> res = (new Solution)->summaryRanges(nums);
  for(string item : res) {
    printf("%s ", item);
  }
}