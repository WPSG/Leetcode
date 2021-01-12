/*
 * @Date: 2021-01-12 14:18:31
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-12 15:47:51
 * @FilePath: \Leetcode\C++\0057-insert-interval.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInetrvel){
    vector<vector<int>> res;
    vector<int> present, pos;
    bool isInserted = false; // 用于判断present是否被插入res
    int length = intervals.size();
    if(length == 0){ // 待插入数组为空时，直接插入newIntervel后退出
      res.push_back(newInetrvel);
      return res;
    }
    present = newInetrvel;
    for(int i = 0; i < length; i++){
      pos = intervals[i];
      // 1，pos在present的左边，将pos插入res
      // 2, present已经被插入res，直接将后面的数组插入res
      if(present[0] > pos[1] || isInserted){
        res.push_back(pos);
      } else if(present[1] >= pos[0]) { // present和pos有交集，取二者并集
        present[0] = min(present[0], pos[0]);
        present[1] = max(present[1], pos[1]);
      } else { // pos在present右边，插入present，并将此时的pos插入，修改isInserted为true
        res.push_back(present);
        res.push_back(pos);
        isInserted = true;
      }
    }
    if(!isInserted) // present一次都没有插入，补插入res的最后。
      res.push_back(present);
    return res;
  }
};

int main(){
  vector<vector<int>> intervels = {{2,3},{6,9}};
  vector<int> newIntervel = {0,1};
  vector<vector<int>> res = (new Solution)->insert(intervels, newIntervel);
  int length = res.size();
  for(int i = 0; i < length; i++){
    for(int j = 0; j < 2; j++){
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}
/* 
给出一个无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1：
输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]

示例 2：
输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-interval
 */