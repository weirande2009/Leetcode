#include <vector>
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
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        ListNode* p = head;
        while(p){
            list.push_back(p->val);
            p = p->next;
        }
        int n = list.size();
        int left = 0;
        int right = n-1;
        while(left < right){
            if(list[left] != list[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
        
    }
};