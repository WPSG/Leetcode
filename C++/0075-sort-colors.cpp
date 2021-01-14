/*
 * @Date: 2021-01-14 14:10:04
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-14 16:25:49
 * @FilePath: \Leetcode\C++\0075-sort-colors.cpp
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  /**
   * @Description: 
   *    我们用指针 pos_0 来交换 0，pos_1​ 来交换 1，初始值都为 0。当我们从左向右遍历整个数组时：
   *    - 如果找到了 1，那么将其与 nums[pos_1]进行交换，并将 pos_1向后移动一个位置
   *    - 如果找到了 0，那么将其与nums[pos_0]进行交换，此时如果nums[i](交换后)小于nums[pos_1],再将二者进行交换。
   *      不论是否进行了第二次交换，pos_0, pos_1都自增(因为第一次将0交换至前面，1和2的插入位置均要后移一位)
   * @Author: ROC
   * @param {vector<int>} &nums
   * @return {*}
   */
  void sortColors(vector<int> &nums){
    int pos_0 = 0, pos_1 = 0, length = nums.size();
    for(int i = 0; i < length;i++){
      if(nums[i] == 0){
        swap(nums[i], nums[pos_0]);
        if(nums[i] < nums[pos_1]){
          swap(nums[i], nums[pos_1]);
        }
        pos_0++;
        pos_1++;
      } else if(nums[i] == 1) {
        swap(nums[i], nums[pos_1]);
        pos_1++;
      }
    }
  }
};

int main(){
  vector<int> nums = {2,0,2,1,1,0};
  (new Solution)->sortColors(nums);
  for(int temp : nums){
    printf("%d ", temp);
  }
}
/* 
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、
蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
注意：请不要使用代码库中的排序函数来解决这道题。

进阶：你能想出一个仅使用常数空间的一趟扫描算法吗？

示例 1：
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]

示例 2：
输入：nums = [2,0,1]
输出：[0,1,2]

示例 3：
输入：nums = [0]
输出：[0]

示例 4：
输入：nums = [1]
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
 */