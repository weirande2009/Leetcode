struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head){
            if(head->val != val){
                break;
            }
            head = head->next;
        }
        if(!head || !head->next){
            return head;
        }
        ListNode* last = head;
        ListNode* cur = head->next;
        while(cur){
            if(cur->val == val){
                last->next = cur->next;
            }
            else{
                last = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};