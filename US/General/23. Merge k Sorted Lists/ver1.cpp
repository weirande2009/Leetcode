#include <vector>
#include <limits.h>
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
    int n;
    ListNode* nextNode(vector<ListNode*>& lists){
        int m = INT_MAX;
        int k = -1;
        for(int i=0; i<n; i++){
            if(lists[i]){
                if(lists[i]->val < m){
                    m = lists[i]->val;
                    k = i;
                }
            }
        }
        if(k == -1){
            return nullptr;
        }
        else{
            ListNode* p = lists[k];
            lists[k] = lists[k]->next;
            return p;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* p;
        n = lists.size();
        if(n == 0){
            return nullptr;
        }
        p = nextNode(lists);
        ListNode* head = p;
        if(!p){
            return p;
        }
        while(1){
            p->next = nextNode(lists);
            if(p->next){
                p = p->next;
            }
            else{
                return head;
            }
        }
    }
};