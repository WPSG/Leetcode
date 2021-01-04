/* 
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

示例 3：
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000

示例 4：
输入：nums1 = [], nums2 = [1]
输出：1.00000

示例 5：
输入：nums1 = [2], nums2 = []
输出：2.00000
 
提示：
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106 // 10的6次方

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays */
class Solution0004{
    public double findMedianSortedArrays(int []nums1, int []nums2){
        int m = nums1.length, n = nums2.length;
        double pre = 0, present = 0;
        int pos1 = 0, pos2 = 0,count = 0;
        while(count <= (m+n)/2){
            pre = present;
            if (pos1 < m && (pos2 >= n || nums1[pos1] < nums2[pos2])) {
                present = nums1[pos1++];
            } else {
                present = nums2[pos2++];
            }
            count++;
        }
        return (m+n)%2 == 0 ? (pre + present) / 2 : present;
    } 
    public static void main(String[] args) {
        int nums1[] = {1,3,5,7,9};
        int nums2[] = {2,4,6,8,10};
        System.out.println(new Solution0004().findMedianSortedArrays(nums1, nums2));
    }
}
