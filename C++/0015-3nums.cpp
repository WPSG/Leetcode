#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution{
    public :
        vector<vector<int>> threeSum(vector<int>& nums){
            int n = nums.size();
            sort(nums.begin(), nums.end()); // 排序，默认递增
            vector<vector<int>> res; // 保存所有不重复的三元组
            for(int i = 0; i < n; i++){ // 固定第一个数，将三数之和为零转化成两数之和
                int mid = i + 1, end = n - 1; // 定义要计算的两数指针
                if (i > 0 && nums[i] == nums[i-1])  continue; // 对于固定的数，去重，跳过
                while (mid < end){
                    if(nums[mid] + nums[end] > -nums[i]) // 两数之和大于-nums[i]，end指针右移
                        end--;
                    else if(nums[mid] + nums[end] < -nums[i]) // 两数之和小于-nums[i]，mid指针左移
                        mid++;
                    else { // 符合条件，存储，并将两指针移动，缩小范围
                        res.push_back({nums[i], nums[mid], nums[end]});
                        mid++; end--;
                        while(mid < end && nums[mid] == nums[mid - 1]) mid++; // 去重
                        while(mid < end && nums[end] == nums[end + 1]) end--; // 去重
                    }
                }
            }
            return res;
        }
};

int main(){
    vector<int> nums = {-4,-1,-1,0,1,2};
    vector<vector<int>> res = (new Solution)->threeSum(nums);
    for (int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++){
            printf("%d " , res[i][j]);
            // cout << res[i][j] << ' '; 
        }
        printf("\n");
    }
}
/* 
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
 */