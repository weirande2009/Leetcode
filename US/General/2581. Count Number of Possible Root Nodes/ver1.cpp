#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<unordered_set<int>>& adj, unordered_map<int, unordered_set<int>>& guesses, int& correct_number, int node, int parent){
        if(guesses.find(parent) != guesses.end() && guesses[parent].find(node) != guesses[parent].end()){
            correct_number++;
        }
        for(int child: adj[node]){
            if(child != parent){
                dfs(adj, guesses, correct_number, child, node);
            }
        }
    }

    // compute the correct number for node according to the correct number of parent
    void dfs2(vector<unordered_set<int>>& adj, unordered_map<int, unordered_set<int>>& guesses, int parent_correct_number, int node, int parent, int k, int& count){
        // if both p-n and n-p edges exist, there is no difference
        if(guesses.find(parent) != guesses.end() && guesses[parent].find(node) != guesses[parent].end() && guesses.find(node) != guesses.end() && guesses[node].find(parent) != guesses[node].end() ){
            
        }
        // if only p-n exist, we need to decrease 
        else if(guesses.find(parent) != guesses.end() && guesses[parent].find(node) != guesses[parent].end()){
            parent_correct_number--;
        }
        // if only n-p exist, we need to increase 
        else if(guesses.find(node) != guesses.end() && guesses[node].find(parent) != guesses[node].end()){
            parent_correct_number++;
        }
        else{

        }
        if(parent_correct_number >= k){
            count++;
        }
        for(int child: adj[node]){
            if(child != parent){
                dfs2(adj, guesses, parent_correct_number, child, node, k, count);
            }
        }
    }
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size()+1;
        vector<unordered_set<int>> adj(n);
        unordered_map<int, unordered_set<int>> hashtable_guesses;
        for(vector<int>& edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        for(vector<int>& guess: guesses){
            hashtable_guesses[guess[0]].insert(guess[1]);
        }
        int count = 0;
        // compute correct number if node 0 is the root
        int correct_number = 0;
        dfs(adj, hashtable_guesses, correct_number, 0, -1);
        if(correct_number >= k){
            count++;
        }
        // compute for other nodes
        for(int child: adj[0]){
            if(child != 0){
                dfs2(adj, hashtable_guesses, correct_number, child, 0, k, count);
            }
        }
        return count;
    }
};