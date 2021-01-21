/*
 * @Date: 2021-01-21 14:09:33
 * @LastEditors: ROC
 * @LastEditTime: 2021-01-21 18:49:42
 * @FilePath: \Leetcode\C++\0126-word-ladder-ii.cpp
 */
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 本题主要是利用bfs+dfs+回溯法来寻找所有最优路径
//先利用bfs来建立一个二叉树，根节点为beginWord，在这棵树中，除了endWord会出现重复外，其他都不应该出现重复
// （重复的肯定不是最优路径，可以直接排除），所以直接利用wordList中所有的单词和beginword来建立这棵树，
// 寻找所有的子节点为endWord

class Solution {
public:
  void backtracing(const string& src, const string& dst, unordered_map<string, vector<string>>& next, vector<string>& path, vector<vector<string>> &ans){
    if (src == dst){
      ans.push_back(path);
      return;
    }
    for (const auto& s :next[src]){
      path.push_back(s);
      backtracing(s, dst, next, path, ans);
      path.pop_back();
      }
    }
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> dict;
    for (const auto& w : wordList){
      dict.insert(w);
    }
    if (!dict.count(endWord))
      return ans;
    dict.erase(beginWord);
    dict.erase(endWord);
    unordered_set<string> start{beginWord}, end{endWord};
    unordered_map<string, vector<string>> next;
    bool reversed = false, found = false;
    while (!start.empty()){
      unordered_set<string> q; //存储下一层节点
      for (const auto& w: start){
        string s = w;
        //从父节点找相邻的子节点
        for (int i = 0; i < w.size(); ++i){
          char ch = s[i];
          for (int j = 0; j < 26; ++j){
            s[i] = j + 'a';
            if (end.count(s)){ // 如果在另一头已经出现， 表示路径汇合
              reversed ? next[s].push_back(w) : next[w].push_back(s);
              found = true;
            }
            if (dict.count(s)){
              //记录每个父节点的所有子节点
              //反向遍历时父节点和子节点的位置要调换
              reversed ? next[s].push_back(w) : next[w].push_back(s);
              q.insert(s); //下一层的节点
            }
          }
          s[i] = ch; //还原父节点
        }
      }
      if (found)
        break;
      for (const auto& w: q){
        dict.erase(w); //删除遍历过的子节点
      }
      // 把下一层节点存进队列
      if (q.size() <= end.size()){
        start = q; 
      }
      else{
        reversed = !reversed;
        start = end;
        end = q;
      }
    }
    //dfs寻找所有的最优队列
    if (found){
      vector<string> path{beginWord};
      backtracing(beginWord, endWord, next, path, ans);
    }
    return ans;
  }
};

int mian(){
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot","dot","dog","lot","log","cog"}; 
  vector<vector<string>> res = (new Solution)->findLadders(beginWord, endWord, wordList);
  printf("%d\n", res.size());
  for(int i = 0; i < res.size(); i++){
    printf("%d ", res[i].size());
  }
}