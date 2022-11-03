#include <stack>
using namespace std;

// Algorithm: use stack to record the list

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> s;
        int l = 0;
        ListNode* p = head;
        while(p){
            l++;
            s.push(p);
            p = p->next;
        }
        if(l == n){
            head = head->next;
            return head;
        }
        for(int i=0; i<n; i++){
            s.pop();
        }
        p = s.top();
        p->next = p->next->next;
        return head;
    }
};