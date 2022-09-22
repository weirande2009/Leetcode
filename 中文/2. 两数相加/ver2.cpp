#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p_1 = l1;
        ListNode* p_2 = l2;
        ListNode* last = p_1;
        int up = 0;
        while(1){
            if(p_1 != nullptr){
                if(p_2 != nullptr){
                    p_1->val += p_2->val;
                    p_2 = p_2->next;
                }
            }
            else{
                if(p_2 != nullptr){
                    last->next = new ListNode(p_2->val);
                    p_1 = last->next;
                    p_2 = p_2->next;
                }
                else{
                    if(up){
                        last->next = new ListNode(up);
                        p_1 = last->next;
                    }
                    break;
                }
            }
            p_1->val += up;
            if(p_1->val >= 10){
                p_1->val -= 10;
                up = 1;
            }
            else{
                up = 0;
            }
            last = p_1;
            p_1 = p_1->next;
        }
        return l1;
    }
};

int main(){
    // ListNode* p_1_4 = new ListNode(1);
    ListNode* p_1_3 = new ListNode(9);
    ListNode* p_1_2 = new ListNode(9, p_1_3);
    ListNode* p_1_1 = new ListNode(9, p_1_2);

    ListNode* p_2_4 = new ListNode(9);
    ListNode* p_2_3 = new ListNode(9, p_2_4);
    ListNode* p_2_2 = new ListNode(9, p_2_3);
    ListNode* p_2_1 = new ListNode(9, p_2_2);
    
    Solution s;

    ListNode* result = s.addTwoNumbers(p_1_1, p_2_1);

    while(result){
        cout << result->val;
        result = result->next;
    }
    cout << endl;

}