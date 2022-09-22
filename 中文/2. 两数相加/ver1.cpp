#include <iostream>
#include <unistd.h>
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
        ListNode* sum_list = nullptr;
        ListNode* p_3 = nullptr;
        int up = 0;
        while(1){
            int node_val = 0;
            bool over = false;
            if(p_1 != nullptr && p_2 != nullptr){
                node_val = p_1->val + p_2->val;
                p_1 = p_1->next;
                p_2 = p_2->next;
            }
            else if(p_1 != nullptr){
                node_val = p_1->val;
                p_1 = p_1->next;
            }
            else if(p_2 != nullptr){
                node_val = p_2->val;
                p_2 = p_2->next;
            }
            else{
                if(up == 0){
                    break;  
                }
                over = true;
            }
            node_val += up;
            if(node_val >= 10){
                node_val -= 10;
                up = 1;
            }
            else{
                up = 0;
            }
            ListNode* node = new ListNode(node_val);
            if(sum_list == nullptr){
                sum_list = node;
                p_3 = node;
            }
            else{
                p_3->next = node;
                p_3 = p_3->next;
            }
        }
        return sum_list;
    }
};

int main(){
    ListNode* p_1_4 = new ListNode(1);
    ListNode* p_1_3 = new ListNode(1, p_1_4);
    ListNode* p_1_2 = new ListNode(6, p_1_3);
    ListNode* p_1_1 = new ListNode(4, p_1_2);

    ListNode* p_2_3 = new ListNode(1);
    ListNode* p_2_2 = new ListNode(6, p_2_3);
    ListNode* p_2_1 = new ListNode(4, p_2_2);
    
    Solution s;

    ListNode* result = s.addTwoNumbers(p_1_1, p_2_1);

    while(result){
        cout << result->val;
        result = result->next;
    }
    cout << endl;
}