#include <bits/stdc++.h>
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    void dfs(const vector<NestedInteger>& nestedList, unordered_map<int, vector<int>>& hashtable, int depth, int& max_depth){
        for(const auto& l: nestedList){
            max_depth = max(max_depth, depth);
            if(l.isInteger()){
                hashtable[depth].push_back(l.getInteger());
            }
            else{
                dfs(l.getList(), hashtable, depth+1, max_depth);
            }
        }
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        // key is the depth and value is the number of the depth
        unordered_map<int, vector<int>> hashtable;
        int max_depth = 0;
        dfs(nestedList, hashtable, 1, max_depth);
        int ans = 0;
        for(auto& p: hashtable){
            for(int num: p.second){
                ans += (max_depth - p.first + 1) * num;
            }
        }
        return ans;
    }
};