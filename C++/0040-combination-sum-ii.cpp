/*
 * @Date: 2021-01-06 17:27:03
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-06 20:40:36
 * @FilePath: \Leetcode\C++\0040-combination-sum-ii.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
    int length = candidates.size();
    vector<vector<int>> res;
    // 先排序，后面才能剪枝
    sort(candidates.begin(), candidates.end());
    vector<int> path; // 存放符合条件的路径
    if(length == 0) return res;
    // 
    dfs(res, path, candidates, target, 0, length);
    return res;
  }

  /**
   * @Description: 通过递归寻找不重复的路径
   * @Author: ROC
   * @param {vector<vector<int>>&res,vector<int>&path,vector<int>} &candidates
   * @param {int} target  目标值
   * @param {int} startPos  每次开始的位置下标
   * @param {int} length  数列长度
   * @return {*}
   */
  void dfs(vector<vector<int>> &res, vector<int> &path, vector<int> &candidates, int target, int startPos, int length){
    // 由于进入下一层的时候，小于 0 的枝桠被剪去，因此递归终止条件值只判断等于 0 的情况
    if(target == 0){
      res.push_back(path);
      return ;
    }
    for(int i = startPos; i < length; i++){
      // target - condidates[i] < 0, 因为已经排序，所以后面都不符合条件，减去该整个枝桠。
      if(target < candidates[i]) break ;
      // 减去同一层的元素相同的枝桠，即跳过相同的元素
      if(i > startPos && candidates[i] == candidates[i - 1]) continue;
      path.push_back(candidates[i]);
      // 因为元素不可以重复使用，这里递归传递下去的是 i + 1 而不是 i
      dfs(res, path, candidates, target - candidates[i], i + 1, length);
      path.pop_back();
    }
  }
};

int main(){
  vector<int> candidates = {10,1,2,7,6,1,5};
  int target = 8;
  vector<vector<int>> res = (new Solution)->combinationSum2(candidates, target);
  int length = res.size();
  for (int i = 0; i < length; i++){
    int n = res[i].size();
    printf("%d\n", n);
  }
}
/* 
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。

解题思路：https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
    与0039属于同系列题目。

说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
 */