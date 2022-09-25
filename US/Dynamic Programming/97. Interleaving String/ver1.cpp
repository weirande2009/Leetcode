#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

// Algorithm: Consider this as a board, for each row is s1 and for each column is s2.
// We start from left-top and the end is right-bottom. We can only move right or 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if(n1 + n2 != n3){
            return false;
        }
        if(n1 == 0 && n2 == 0 && n3 == 0){
            return true;
        }
        int column = n1+1;
        int row = n2+1;
        queue<int> q;
        q.push(0);
        unordered_set<int> hashtable;
        while(1){  // Breadth-first Search
            int pos = q.front();
            q.pop();
            int pos1 = pos % column;
            int pos2 = pos / column;
            // Judge s1
            if(pos1 < n1){
                if(s1[pos1] == s3[pos1+pos2]){
                    int q_pos = pos2 * column + pos1 + 1;
                    auto f = hashtable.find(q_pos);
                    if(f == hashtable.end()){
                        q.push(q_pos);
                        hashtable.insert(q_pos);
                    }
                }
            }
            if(pos2 < n2){
                if(s2[pos2] == s3[pos1+pos2]){
                    int q_pos = (pos2 + 1) * column + pos1;
                    auto f = hashtable.find(q_pos);
                    if(f == hashtable.end()){
                        q.push(q_pos);
                        hashtable.insert(q_pos);
                    }
                }
            }
            if(q.empty()){
                return false;
            }
            else if(q.front() == column*row-1){
                return true;
            }
        }
        
    }
};