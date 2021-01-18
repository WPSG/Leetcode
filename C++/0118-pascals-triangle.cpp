/*
 * @Date: 2021-01-18 17:03:59
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-18 17:18:53
 * @FilePath: \Leetcode\C++\0118-pascals-triangle.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
public:
  vector<vector<int>> generate(int & numRows){
    vector<vector<int>> res; vector<int> preRows;
    if(numRows == 0) return res;
    res.push_back({1});
    for(int i = 1; i < numRows; i++){
      vector<int> curRows;
      curRows.push_back(1);
      if(i - 1 != 0){
        for(int j = 0; j < i - 1; j++){
        curRows.push_back(preRows[j] + preRows[j + 1]);
      }
      }
      curRows.push_back(1);
      res.push_back(curRows);
      preRows = curRows;
    }
    return res;
  }
};
int main(){
  int numRows = 0;
  vector<vector<int>> res = (new Solution)->generate(numRows);
  int lastLength = res[numRows - 1].size();
  for(int i = 0; i < lastLength; i++){
    printf("%d ", res[numRows - 1][i]);
  }
}