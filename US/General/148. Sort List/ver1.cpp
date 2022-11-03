#include <vector>
#include <algorithm>
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
    ListNode* sortList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        vector<ListNode*> list;
        ListNode* p = head;
        while(p){
            list.push_back(p);
            p = p->next;
        }
        sort(list.begin(), list.end(), [](ListNode* p1, ListNode* p2){
            return p1->val < p2->val;
        });
        int n = list.size();
        list[n-1]->next = nullptr;
        for(int i=n-2; i>=0; i--){
            list[i]->next = list[i+1];
        }
        return list[0];
    }
};
