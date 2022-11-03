#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hashtable;
        ListNode *p = head;
        while(p){
            if(hashtable.find(p) == hashtable.end()){
                hashtable.insert(p);
            }
            else{
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};