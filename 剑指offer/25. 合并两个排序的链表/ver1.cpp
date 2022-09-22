#include <cstring>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(-1);
        ListNode* head = p;
        p->next = l1;
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        while(l2){
            bool inserted = false;
            while(p->next){
                if(l2->val < p->next->val){
                    ListNode* tmp = p->next;
                    p->next = l2;
                    l2 = l2->next;
                    p->next->next = tmp;
                    p = p->next;
                    inserted = true;
                    break;
                }
                p = p->next;
            }
            if(!inserted){
                p->next = l2;
                break;
            }
        }
        ListNode* tmp = head->next;
        return tmp;
    }
};

int main(){
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(1);
    Solution s;
    s.mergeTwoLists(l1, l2);


}
