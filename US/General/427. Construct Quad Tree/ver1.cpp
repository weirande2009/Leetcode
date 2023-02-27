#include <bits/stdc++.h>
using namespace std;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* dfsbuild(vector<vector<int>>& grid, int begin_row, int end_row, int begin_col, int end_col){
        int ones = 0;
        int zeros = 0;
        bool is_leaf = true;
        for(int i=begin_row; i<=end_row; i++){
            for(int j=begin_col; j<=end_col; j++){
                if(grid[i][j] == 1){
                    if(zeros != 0){
                        is_leaf = false;
                        break;
                    }
                    ones++;
                }
                else{
                    if(ones != 0){
                        is_leaf = false;
                        break;
                    }
                    zeros++;
                }
            }
            if(!is_leaf){
                break;
            }
        }
        if(is_leaf){
            Node* node = new Node();
            node->isLeaf = true;
            if(ones > 0){
                node->val = true;
            }
            else{
                node->val = false;
            }
            return node;
        }
        else{
            Node* node = new Node();
            node->val = true;
            node->isLeaf = false;
            node->topLeft = dfsbuild(grid, begin_row, (begin_row+end_row)/2, begin_col, (begin_col+end_col)/2);
            node->topRight = dfsbuild(grid, begin_row, (begin_row+end_row)/2, (begin_col+end_col)/2+1, end_col);
            node->bottomLeft = dfsbuild(grid, (begin_row+end_row)/2+1, end_row, begin_col, (begin_col+end_col)/2);
            node->bottomRight = dfsbuild(grid, (begin_row+end_row)/2+1, end_row, (begin_col+end_col)/2+1, end_col);
            return node;
        }
    }


    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfsbuild(grid, 0, n-1, 0, n-1);
    }
};