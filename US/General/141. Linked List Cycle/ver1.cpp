#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hashtable;
        ListNode *p = head;
        while(p){
            if(hashtable.find(p) == hashtable.end()){
                hashtable.insert(p);
            }
            else{
                return true;
            }
            p = p->next;
        }
        return false;
    }
};