/*
 * @Date: 2021-01-07 15:02:34
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-07 19:03:26
 * @FilePath: \Leetcode\C++\0042-trapping-rain-water.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  int trap(vector<int> &height){
    int n = height.size(), sum = 0;
    int leftMax = 0; // 存放当前列左边的最高列的坐标
    int *rightMax = new int[n]; // 存放当前列右边的最高列的坐标
    // 初始化成0
    fill(rightMax, rightMax + n, 0);
    for(int i = n - 2; i >= 0; i--){
      int max = (height[i + 1] - rightMax[i + 1] > 0) ? height[i + 1] : rightMax[i + 1];
      printf("%d ", max);
      rightMax[i] = max;
    }
    printf("\n");
    // 计算每一列的水量。通过比较列值和左右两个最高列的关系计算每一列的水量
    for(int i = 1; i < n - 1; i++){
      // 获得当前列的左边最高列坐标
      int max = (height[i - 1] - leftMax > 0) ? height[i - 1] : leftMax;
      leftMax = max;
      int min = leftMax - rightMax[i] > 0 ? rightMax[i] : leftMax;
      if(min > height[i])
        sum += (min - height[i]);
    }
    return sum;
  }
};

int main(){
  vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
  int res = (new Solution) -> trap(height);
  printf("%d", res);
}
/* 
  给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：
输入：height = [4,2,0,3,2,5]
输出：9
提示：
n == height.length
0 <= n <= 3 * 10^4
0 <= height[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
 */