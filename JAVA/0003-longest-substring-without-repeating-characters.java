import java.util.HashMap;
import java.util.Map;

/* 
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

示例 4:
输入: s = ""
输出: 0
 
提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
*/
class Solution0003 {
    public int lengthOfLongestSubstring(String s) {
        int stringLength = s.length(); 
        int subStringLength = 0;
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        if(stringLength == 0)  // 如果输入的字符串长度为0，则返回0
            return 0;
        /* start始终指向不重复子串的起始位置，不断地查询end指向的元素是否存在在map中，如果存在，则修改start值为start和
             map.get(character) + 1 中的最大值，如果不存在，则将end指向的元素和地址下标存入map*/
        for(int start = 0, end = 0; end < stringLength; end++){ 
            char character = s.charAt(end);
            if(map.containsKey(character)){
                start = Math.max(start, map.get(character) + 1);
            }
            map.put(character, end);
            subStringLength = Math.max(subStringLength, end - start + 1);
        }
        return subStringLength;
    }
    public static void  main(String Args[]){
        String s = "fhafhuahsdfcvasfvchsudfv";
        System.out.println(s + '\n' + new Solution0003().lengthOfLongestSubstring(s));
    }
}
