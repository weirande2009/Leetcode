struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* recursion(ListNode* head) {
        if(!head->next->next){
            head->next->next = head;
            return head->next;
        }
        else{
            ListNode* p = recursion(head->next);
            head->next->next = head;
            return p;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return head;
        }
        if(!head->next){
            return head;
        }
        ListNode* result = recursion(head);
        head->next = nullptr;
        return result;
    }
};