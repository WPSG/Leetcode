/* 
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
https://leetcode-cn.com/problems/add-two-numb
*/
class ListNode{
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution0002 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sumList , p;
        sumList = new ListNode();
        p = sumList;
        int carry = 0;
        int sumTemp = 0;
        // 两个链表逐个相加，记录进位
        while(l1 != null && l2 != null){
            if ((l1.val + l2.val + carry) >= 10) {
                sumTemp = (l1.val + l2.val + carry) % 10;
                carry = 1;
            } else {
                sumTemp = l1.val + l2.val + carry;
                carry = 0;
            }
            p.val = sumTemp;
            if(l1.next != null || l2.next != null){
                p.next = new ListNode();
                p = p.next;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        // 处理多余出来的链表
        if(l1 != null)
            l2 = l1;
        while(l2 != null) {
            if ((l2.val + carry) >= 10) {
                sumTemp = (l2.val + carry) % 10;
                carry = 1;
            } else {
                sumTemp = l2.val + carry;
                carry = 0;
            }
            p.val = sumTemp;
            if(l2.next != null){
                p.next = new ListNode();
                p = p.next;
            } 
            l2 = l2.next;
        }
        // 最后的一位进位数据添加到链表的最后
        if(carry == 1){
            p.next = new ListNode(carry);
        }
        return sumList;
    }

    public static void main(String []args){
        ListNode l1 = new ListNode(3);
        ListNode l2 = new ListNode(4);
        ListNode test = new Solution0002().addTwoNumbers(l1, l2);
        while(test!=null){
            System.out.println(test.val);
            test = test.next;
        }
    }
}
