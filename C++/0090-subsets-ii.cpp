/*
 * @Date: 2021-01-17 14:18:17
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-17 15:30:11
 * @FilePath: \Leetcode\C++\0090-subsets-ii.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums){
      sort(nums.begin(), nums.end()); // 排序，是剪枝必要步骤
      vector<vector<int>> res; vector<int> path;
      int length = nums.size();
      dfs(nums, res, 0, path, length);
      return res;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &res, int startPos, vector<int> &path, int length){
      res.push_back(path);
      for(int i = startPos; i < length; i++){
        if(i > startPos && nums[i] == nums[i - 1]) continue; // 同层相同元素跳过
        path.push_back(nums[i]);
        dfs(nums, res, i + 1, path, length);
        path.pop_back();
      }
    }
};
int main(){
  vector<int> nums = {1,2,2};
  vector<vector<int>> res = (new Solution)->subsetsWithDup(nums);
  int length = res.size();
  printf("%d", length);
}
/* 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

示例:
输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */