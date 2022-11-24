struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* p = head;
        while(p){
            count++;
            p = p->next;
        }
        int target = count/2;
        p = head;
        for(int i=0; i<target; i++){
            p = p->next;
        }
        return p;
    }
};