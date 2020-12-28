package Array;

/* 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

import java.util.HashMap;

class Solution {
    public int[] twoSum(int []nums,int target){
        HashMap<Integer, Integer> hashMap = new HashMap<Integer,Integer>();
        int []indexes = new int[2];
        for(int i = 0; i < nums.length; i++){
            if(hashMap.containsKey(nums[i])){
                indexes[0] = hashMap.get(nums[i]);
                indexes[1] = i;
                return indexes;
            }
            hashMap.put(target - nums[i], i);
        }
        return indexes;
    }

    public static void main(String []args) {
        int []nums = {2,43,65,21,57,54};
        int target = 100;
        int []indexes = new int[2];
        indexes = new Solution().twoSum(nums, target);
        for (int i : indexes) {
            System.out.println("第" + i + "个数的坐标是" + i);
        }
    }
}