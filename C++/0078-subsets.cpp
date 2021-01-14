/*
 * @Date: 2021-01-14 16:30:05
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-14 18:51:20
 * @FilePath: \Leetcode\C++\0078-subsets.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
  public:
    vector<int> paths;
    vector<vector<int>> res;

    void dfs(int current, vector<int>& nums) {
      int length = nums.size();
      if (current == length) {
          res.push_back(paths);
          return;
      }
      paths.push_back(nums[current]);
      dfs(current + 1, nums);
      paths.pop_back();
      dfs(current + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
      dfs(0, nums);
      return res;
    }
};

int main(){
  vector<int> nums = {1,2,3};
  vector<vector<int>> res = (new Solution)->subsets(nums);
  int length = res.size();
  printf("%d", length);
}
/* 
给你一个整数数组 nums ，返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。
 
示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

示例 2：
输入：nums = [0]
输出：[[],[0]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
 */