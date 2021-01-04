#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution{
    public:
        int threeSumClosest(vector<int> &nums, int target){
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int res = 0; // 存放结果
            int diff = 1981284352; // 记录当前最小的差值
            for(int i = 0; i < n; i++){// 固定第一个数，移动mid，end指针选择第二，第三个数。
                int mid = i + 1, end = n - 1;
                if (i > 0 && nums[i] == nums[i-1])  continue; // 去重，跳过
                while(mid < end){
                    int sum = nums[i] + nums[mid] + nums[end];
                    if(abs(sum - target) < diff){ // 比较三书与target差值与当前最小差值的大小
                        res = sum; diff = abs(sum - target);
                    } else if(sum > target){ // 和过大，则左移end指针
                        end--;
                        while(mid < end && nums[end] == nums[end + 1]) end--;//对于已计算过的数，跳过
                    }    
                    else if(sum < target){ // 和过小，则右移mid指针
                         mid++; 
                         while(mid < end && nums[mid] == nums[mid - 1]) mid++;//对于已计算过的数，跳过
                    }
                    else 
                        return res;  
                }
            }
            return res;
        }
};

int main(){
    vector<int> nums = {-1,2,1,-4};
    int res = (new Solution)->threeSumClosest(nums, 1);
    printf("%d", res);
}
/* 
    给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 
提示：
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
 */