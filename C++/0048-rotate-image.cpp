/*
 * @Date: 2021-01-10 13:39:17
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-10 14:52:29
 * @FilePath: \Leetcode\C++\0048-rotate-image.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  /*
  * clockwise rotate 顺时针旋转
  * first reverse up to down, then swap the symmetry 
  * 1 2 3     7 8 9     7 4 1
  * 4 5 6  => 4 5 6  => 8 5 2
  * 7 8 9     1 2 3     9 6 3
  */
  void rotate(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int swap = 0;
    reverse(matrix.begin(), matrix.end());
    for(int i = 0; i < rows; i++){
      for(int j = i + 1; j < rows; j++){
        swap = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = swap;
      }
    }
  }
};

int main(){
  vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
  int rows = matrix.size();
  (new Solution) -> rotate(matrix);
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < rows; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

/* 
给定一个 n × n 的二维矩阵表示一个图像。将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
示例 1:
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 */