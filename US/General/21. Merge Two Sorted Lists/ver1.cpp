struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p,* head;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        if(!list1 && !list2){
            return list1;
        }
        else if(!list1){
            return list2;
        }
        else if(!list2){
            return list1;
        }
        else{
            if(list1->val > list2->val){
                p = list2;
                p2 = p2->next;
            }
            else{
                p = list1;
                p1 = p1->next;
            }
        }
        head = p;
        while(1){
            if(p1 && p2){
                if(p1->val < p2->val){
                    p->next = p1;
                    p1 = p1->next;
                }
                else{
                    p->next = p2;
                    p2 = p2->next;
                }
                p = p->next;
            }
            else if(!p1){
                p->next = p2;
                break;
            }
            else if(!p2){
                p->next = p1;
                break;
            }
            else{
                break;
            }
        }
        return head;
    }
};