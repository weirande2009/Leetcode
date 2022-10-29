#include <vector>
using namespace std;

// Algorithm: Use a vector to record each node.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        ListNode* p = head;
        while(p){
            list.push_back(p);
            p = p->next;
        }
        int n = list.size();
        int left = 0;
        int right = n-1;
        while(left < right){
            list[right-1]->next = nullptr;
            list[right]->next = list[left]->next;
            list[left]->next = list[right];
            left++;
            right--;
        }
    }
};