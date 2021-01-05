#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
      vector<vector<int>> fourSum(vector<int> & nums, int target){
        int n = nums.size(); // 获取长度
        sort(nums.begin(), nums.end()); // 排序
        int firstPos = 0, secondPos = 0, thirdPos = 0, endPos = n - 1;
        vector<vector<int>> res; // 存放结果
        for(int i = 0; i < n - 3; i++){ // 固定第一个数值
          if(i > 0 && nums[i] == nums[i - 1]) continue; //去重
          for(int j = i + 1; j < n - 2; j++){ // 固定第二个数值
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;// 去重
            firstPos = i; secondPos = j; thirdPos = j + 1; endPos = n - 1; // 确定四个数的初始位置
            while(thirdPos < endPos){ // 移动未固定的两个数的指针，使之符合条件
              int sum = nums[firstPos] + nums[secondPos] + nums[thirdPos] + nums[endPos];
              if( sum > target ) // 四数之和大于目标值，移动endPos
                endPos--;
              else if(sum < target )// 四数之和小于目标值，移动thirdPos
                thirdPos++;
              else{ // 符合条件，装入res,并移动thirdPos,endPos
                res.push_back({nums[firstPos], nums[secondPos], nums[thirdPos], nums[endPos]});
                thirdPos++; endPos--;
                while(thirdPos < endPos && nums[thirdPos] == nums[thirdPos - 1]) thirdPos++;// 去重
                while(thirdPos < endPos && nums[endPos] == nums[endPos + 1]) endPos--; // 去重
              }
            }
          }
        }
        return res;
      }
};

int main(){
  vector<int> nums = {-2,-1,-1,1,1,2,2};
  int target = 0;
  vector<vector<int>> res = (new Solution)->fourSum(nums, target);
  int rows = res.size();
  int columns = res[0].size();
  for(int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}

/* 
    给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意：
答案中不可以包含重复的四元组。
示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
 */