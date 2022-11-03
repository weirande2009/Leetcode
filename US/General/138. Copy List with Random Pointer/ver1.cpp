#include <vector>
#include <stdlib.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        vector<Node*> list;
        Node* p = head;
        while(p){
            list.push_back(p);
            p = p->next;
        }
        int n = list.size();
        vector<Node*> new_list;
        vector<int> random_i;
        for(int i=0; i<n; i++){
            new_list.push_back(new Node(list[i]->val));
            if(list[i]->random == nullptr){
                random_i.push_back(-1);
            }
            else{
                for(int j=0; j<n; j++){
                    if(list[i]->random == list[j]){
                        random_i.push_back(j);
                    }
                }
            }
            
        }
        for(int i=0; i<n; i++){
            if(i != n-1){
                new_list[i]->next = new_list[i+1];
            }
            if(random_i[i] == -1){
                new_list[i]->random = nullptr;
            }
            else{
                new_list[i]->random = new_list[random_i[i]];
            }
        }
        return new_list[0];
    }
};