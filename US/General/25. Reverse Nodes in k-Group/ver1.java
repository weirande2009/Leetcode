/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ArrayList<ListNode> list = new ArrayList();
        ListNode p = head;
        while(p != null){
            list.add(p);
            p = p.next;
        }
        int n = list.size();
        list.get(0).next = null;
        for(int i=1; i<n; i++){
            if(i%k == 0 && i != 0){
                if(n-i < k){
                    list.get(i-k).next = list.get(i);
                    break;
                }
                else{
                    list.get(i-k).next = list.get(i+k-1);
                    list.get(i).next = null;
                }
            }
            else{
                list.get(i).next = list.get(i-1);
            }
        }
        return list.get(k-1);
    }
}