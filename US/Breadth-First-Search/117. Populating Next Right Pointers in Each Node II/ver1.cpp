#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            queue<Node*> new_q;
            while(!q.empty()){
                if(q.front()->left)
                    new_q.push(q.front()->left);
                if(q.front()->right)
                    new_q.push(q.front()->right);
                Node* tmp = q.front();
                q.pop();
                if(!q.empty()){
                    tmp->next = q.front();
                }
                
            }
            q = new_q;
        }
        return root;
    }
};