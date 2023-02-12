#include <bits/stdc++.h>
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
        stack<int> s1;
        stack<int> s2;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while(p1){
            s1.push(p1->val);
            p1 = p1->next;
        }
        while(p2){
            s2.push(p2->val);
            p2 = p2->next;
        }
        int carry = 0;
        stack<int> s;
        while(1){
            int sum = carry;
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            if(sum >= 10){
                carry = 1;
                sum -= 10;
            }
            else{
                carry = 0;
            }
            s.push(sum);
            if(carry == 0 && s1.empty() && s2.empty()){
                break;
            }
        }
        ListNode* head = new ListNode(s.top());;
        ListNode* p = head;
        s.pop();
        while(!s.empty()){
            p->next = new ListNode(s.top());
            s.pop();
            p = p->next;
        }
        return head;
    }
};