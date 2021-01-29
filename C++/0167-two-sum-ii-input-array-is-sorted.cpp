/*
 * @Author: ROC
 * @Date: 2021-01-29 14:44:50
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-29 15:02:00
 * @FilePath: \Leetcode\C++\0167-two-sum-ii-input-array-is-sorted.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
  public:
    vector<int> twoSum(vector<int> &nums, int target){
      int i = 0, j = nums.size() - 1;
      vector<int> res;
      while(i < j){
        if(nums[i] + nums[j] == target){
          res.push_back(i + 1);
          res.push_back(j + 1);
          return res;
        }
        else if(nums[i] + nums[j] < target)
          i++;
        else 
          j--;
      }
      return res;
    }
};

int main(){
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> res = (new Solution)->twoSum(nums, target);
  int length = res.size();
  for(int i = 0; i < length; i++){
    printf("%d ", res[i]);
  }
}