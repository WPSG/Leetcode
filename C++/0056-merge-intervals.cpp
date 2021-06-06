/*
 * @Date: 2021-01-11 15:04:36
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-06 09:37:47
 * @FilePath: \Leetcode\C++\0056-merge-intervals.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  /**
   * @Description: 先根据区间的起始位置排序，再进行n−1次两两合并。
   * @Author: ROC
   * @param {*}
   * @return {*}
   */
  vector<vector<int>> merge(vector<vector<int>> &intervels){
    vector<vector<int>> res;
    if(intervels.size() == 0) return res;
    sort(intervels.begin(), intervels.end());
    vector<int> pre = intervels[0];
    for(vector<int> curr : intervels) {
      if(pre[1] < curr[0]) {
        res.push_back(pre);
        pre = curr;
      } else {
        pre[1] = max(pre[1], curr[1]);
      }
    }
    res.push_back(pre);
    return res;
  }
};

int main(){
  vector<vector<int>> intervels = {{1,3},{2,6},{8,10},{15,18}};
  vector<vector<int>> res;
  res = (new Solution)->merge(intervels);
  int length = res.size();
  for(int i = 0; i < length; i++){
    for(int j = 0; j < 2; j++){
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}
/* 
给出一个区间的集合，请合并所有重叠的区间。

示例 1:
输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:
输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
 */