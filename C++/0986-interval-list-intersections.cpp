/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-06 09:52:05
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-07 21:00:22
 * @FilePath: \Leetcode\C++\0986-interval-list-intersections.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
  public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    vector<vector<int>> res;
    // 两个指针
    int i = 0, j = 0;
    int start = 0, end = 0;
    while(i < firstList.size() && j < secondList.size()) {
      start = max(firstList[i][0], secondList[j][0]);
      end = min(firstList[i][1], secondList[j][1]);
      // 闭区间，所以是小于等于
      if(start <= end) {
        res.push_back({start, end});
      }
      // 去判断下一个
      firstList[i][1] < secondList[j][1] ? ++i : ++j;
    }
    return res;
  }
};
