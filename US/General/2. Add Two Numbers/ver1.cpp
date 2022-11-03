struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    
private:
    void add(int& des, int inc, int& carry){
        des += inc + carry;
        if(des >= 10){
            des -= 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int n1 = 0;
        int n2 = 0;
        while(p1){
            n1++;
            p1 = p1->next;
        }
        while(p2){
            n2++;
            p2 = p2->next;
        }
        ListNode* result;
        if(n2 > n1){
            p1 = l2;
            p2 = l1;
            result = l2;
        }
        else{
            p1 = l1;
            p2 = l2;
            result = l1;
        }
        int carry = 0;
        while(1){
            if(p1 && p2){
                add(p1->val, p2->val, carry);
            }
            else if(p1){
                while(1){
                    add(p1->val, 0, carry);
                    if(!p1->next){
                        break;
                    }
                    p1 = p1->next;
                }
                if(carry){
                    p1->next = new ListNode(carry);
                }
                break;
            }
            if(!p1->next && !p2->next){
                if(carry){
                    p1->next = new ListNode(carry);
                }
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return result;
    }
};