/*
 * @Date: 2021-01-15 14:01:04
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-15 17:19:53
 * @FilePath: \Leetcode\C++\0079-word-search.cpp
 */
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution{
  public:
    bool exist(vector<vector<char>>& board, int i, int j, string & word, int s){
      if (s >= word.size()) return true;
      if (board[i][j] != word[s])  return false;
      if (s+1 == word.size()) return true;
      char ok = board[i][j];
      board[i][j] = '0';
      if (i - 1 >= 0 && exist(board, i-1, j, word, s+1)) { board[i][j] = ok; return true;}
      if (j - 1 >= 0 && exist(board, i, j-1, word, s+1)) { board[i][j] = ok; return true;}
      if (i + 1 < board.size()&& exist(board, i+1, j, word, s+1)) { board[i][j] = ok; return true;}
      if (j + 1 < board[0].size() && exist(board, i, j+1, word, s+1)) { board[i][j] = ok; return true;}
      board[i][j] = ok;
      return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
      int n = board.size(); if (n <= 0) return false;
      int m = board[0].size(); if (m <= 0) return false;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          if (exist(board,i,j,word,0)) return true;
        }
      }
      return false;
    }
};
int main(){
  vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  string word = "ABCCED";
  bool res = (new Solution)->exist(board, word);
  printf("%d", res);
}
/* 
给定一个二维网格和一个单词，找出该单词是否存在于网格中。单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
 */