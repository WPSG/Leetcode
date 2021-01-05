#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution{
    public:
        int removeElement01(vector<int> &nums, int val){ // 用step记录要移动的距离，与val不等时向前移动step个位置
            int n = nums.size();
            int step = 0;
            if(nums.size() == 0) return 0;
            for (int i = 0; i < n; i++){
                if(nums[i] == val){
                    step++;
                }else{
                    nums[i - step] = nums[i];
                }
                
            }
            return nums.size() - step;
        }
        int removeElement02(vector<int>& nums, int val) { // 用pos记录要插入的位置，不与val相等时插入
            int n = nums.size();
            int pos = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] != val) {
                    nums[pos] = nums[i];
                    pos++;
                }
            }
            return pos;
	}
};

int main(){
    vector<int> nums = {3,2,2,3};
    int val = 3;
    printf("%d", (new Solution)->removeElement02(nums, val));
}
/* 
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,1,2,2,3,0,4,2], val = 2,
函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
注意这五个元素可为任意顺序。
你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
 */