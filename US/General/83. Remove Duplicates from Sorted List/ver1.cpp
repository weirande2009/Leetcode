struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* last = head;
        if(last == nullptr){
            return last;
        }
        ListNode* p = last->next;
        while(p){
            if(last->val == p->val){
                last->next = p->next;
            }
            else{
                last = p;
            }
            p = p->next;
        }
        return head;
    }
};