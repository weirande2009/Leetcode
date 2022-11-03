#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hashtable;
        ListNode* p = headA;
        while(p){
            hashtable.insert(p);
            p = p->next;
        }
        p = headB;
        while(p){
            if(hashtable.find(p) != hashtable.end()){
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};