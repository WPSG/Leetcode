package JAVA;

class Solution0867 {
    public int[][] tranpose(int [][] A){
        int width = A.length, height = A[0].length;
        int [][]B = new int[height][width];
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                 B[j][i] = A[i][j];
            }
        }
        return B;
    }
    public static void main(String [] Args){
        int [][] B = {{1,2,3,},{4,5,6}};
        int [][] A = new Solution0867().tranpose(B);
        int width = A.length, height = A[0].length;
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                System.out.print(A[i][j]);
            }
            System.out.println();
        }
    }

}
/* 
给定一个矩阵 A， 返回 A 的转置矩阵。
矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

示例 1：
输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]

示例 2：
输入：[[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]

提示：
1 <= A.length <= 1000
1 <= A[0].length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/transpose-matrix
*/