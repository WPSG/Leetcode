/*
 * @Description: 
 * @Author: ROC
 * @Date: 2021-06-05 20:49:04
 * @LastEditors: ROC
 * @LastEditTime: 2021-06-06 08:57:35
 * @FilePath: \Leetcode\C++\1288-remove-covered-intervals.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
  int removeCoveredIntervals(vector<vector<int>>& intervels) {
    // 将线段按照首部升序排列，如果首部相同，那么按照尾部降序排列
    sort(begin(intervels), end(intervels),
    [](const vector<int>& o1, const vector<int>& o2) {
      return o1[0] == o2[0] ? o2[1] < o1[1] : o1[0] < o2[0];
    });
    
    int count = 0;
    int end = 0, pre = 0;
    for(vector<int> tmp : intervels) {
      end = tmp[1];
      if(pre < end) {
        count++;
        pre = end;
      }
    }
    return count;
  }
};

int main() {
  vector<vector<int>> intervels = {{1,4},{3,6},{2,8}};
  int res = (new Solution) -> removeCoveredIntervals(intervels);
  printf("%d\n", res);
  return res;
}