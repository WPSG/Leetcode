#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    // 排序是剪枝的前提
    sort(candidates.begin(), candidates.end());
    int length = candidates.size();
    if(length == 0) return res;
    vector<int> path;
    dfs(candidates, path, res, target, 0, length);
    return res;
  }

  /**
   * @Description: 通过递归寻找不重复的路径
   * @Author: ROC
   * @param {vector<int>&candidates,vector<int>path,vector<vector<int>>&res} 
   * @param {int} target  目标值
   * @param {int} startPos  每次开始的位置下标
   * @param {int} length  数列长度
   * @return {*}
   */  
  void dfs(vector<int> &candidates, vector<int> path, vector<vector<int>> &res, int target, int startPos, int length){
    // 由于进入更深层的时候，小于 0 的部分被剪枝，因此递归终止条件值只判断等于 0 的情况
    if(target == 0) {
      res.push_back(path);
      return ;
    }
    for(int i = startPos; i < length; i++){
      // 重点理解这里剪枝，前提是候选数组已经有序，
      if (target - candidates[i] < 0) {
          break;
      }
      path.push_back(candidates[i]);
      dfs(candidates, path, res, target - candidates[i], i, length);
      path.pop_back();
    }
  }
};
int main(){
  vector<int> candidates = {2,3,6,7};
  int target = 7;
  vector<vector<int>> res = (new Solution)->combinationSum(candidates, target);
  int rows = res.size();
  for(int i = 0; i < rows; i++){
    printf("%d", (int)res[i].size());
    printf("\n");
  }
}
/* 
    给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

‼‼‼‼ 解题思路：https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：
输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：
输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
提示：
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
 */