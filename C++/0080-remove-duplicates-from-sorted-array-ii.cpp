/*
 * @Date: 2021-01-16 13:53:54
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-16 15:02:27
 * @FilePath: \Leetcode\C++\0080-remove-duplicates-from-sorted-array-ii.cpp
 */
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
  public: 
    int removeDuplicates(vector<int> &nums){
      int length = nums.size();
      if(length <= 2) return length;
      int count = 1, curPos = 1; // count表示元素重复次数，curPos表示即将插入的位置。
      /* 从第二个元素开始遍历， 
      - 如果当前元素与前一个元素相等且重复次数小于2，则向前移动到curPos处，并将count自增
      - 如果当前元素与前一个元素不相等，则直接前移至curPos处，并将count置为1.
      */
      for(int i = 1; i < length; i++){
        if(nums[i] == nums[i - 1] && count < 2){
          nums[curPos] = nums[i];
          curPos++;
          count++;
        } else if(nums[i] != nums[i - 1]) {
          nums[curPos] = nums[i];
          curPos++;
          count = 1;
        }
      }
      return curPos;
    }
};

int main(){
  vector<int> nums = {0,0,0,1,1,1,1,2,3,3};
  int res = (new Solution)->removeDuplicates(nums);
  printf("%d\n", res);
  for(int i = 0; i < res; i++){
    printf("%d ", nums[i]);
  }
}
/* 
给定一个增序排列数组 nums ，你需要在 原地 删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

示例 1：
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 你不需要考虑数组中超出新长度后面的元素。

示例 2：
输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。 你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
 */