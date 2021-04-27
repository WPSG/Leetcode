/*
 * @Author: ROC
 * @Date: 2021-01-30 15:59:51
 * @LastEditors: ROC
 * @LastEditTime: 2021-04-27 15:33:27
 * @FilePath: \Leetcode\C++\0216-combination-sum-iii.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  void backTrack(vector<int> &cur, int k, int target, int cnt, int idx)
  {
    if (k == 0 && cnt == target) {
      ans.emplace_back(cur);
      return;
    }
    if (k == 0) return;
    if (cnt >= target) return;
    for (int i = idx; i <= 9; ++i) {
      if (i + cnt > target) return; // 从小到大遍历，后面的更大，需要剪枝
      cur.emplace_back(i);
      backTrack(cur, k - 1, target, cnt + i, i + 1); // 解集不重复，下一次需要从 i + 1 开始
      cur.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int target) {
    vector<int> cur;
    backTrack(cur, k, target, 0, 1);
    return ans;
  }
};

int main(){
  int k = 3, n = 9;
  vector<vector<int>> res = (new Solution)->combinationSum3(k, n);
  int length = res.size();
  for(int i = 0; i < length; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}