#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(vector<int>& list, int begin, int end){
        if(begin == end){
            return new TreeNode(list[begin]);
        }
        else if(begin > end){
            return nullptr;
        }
        else{
            TreeNode* node = new TreeNode(list[(begin+end)/2]);
            node->left = dfs(list, begin, (begin+end)/2-1);
            node->right = dfs(list, (begin+end)/2+1, end);
            return node;
        }
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vector_list;
        while(head){
            vector_list.push_back(head->val);
            head = head->next;
        }
        return dfs(vector_list, 0, vector_list.size()-1);
    }
};