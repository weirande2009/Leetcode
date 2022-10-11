#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Algorithm: Consider this as a problem of graph. First construct the graph by record
// each node(char)'s in nodes(char is smaller than this).
// Then use while to find a node with zero in nodes, which means it's the smallest currently.
// Then delete all the nodes's in nodes which has this node. Then take the next loop until
// The there is no zero innodes nodes or we have iterate over all the nodes.


class Solution {
public:
    int getFirstDifPos(const string& s1, const string& s2){
        int n = s1.length() > s2.length() ? s2.length() : s1.length();
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                return i;
            }
        }
        if(s1.length() > s2.length()){
            return -2;
        }
        return -1;
    }
    
    string alienOrder(vector<string>& words) {
        // Record the innode of a node
        unordered_map<char, unordered_set<char>> nodes;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].length(); j++){
                if(nodes.find(words[i][j]) == nodes.end()){
                    nodes[words[i][j]] = unordered_set<char>();
                }
            }
        }
        for(int i=1; i<n; i++){
            int pos = getFirstDifPos(words[i-1], words[i]);
            if(pos >= 0){
                nodes[words[i][pos]].insert(words[i-1][pos]);
            }
            else if(pos == -2){
                return "";
            }
        }
        string result;
        int letter_num = nodes.size();
        while(1){
            bool flag = false;
            for(auto& node: nodes){
                if(node.second.size() == 0){
                    flag = true;
                    result += node.first;
                    for(auto& no: nodes){
                        if(no.first != node.first){
                            if(no.second.find(node.first) != no.second.end()){
                                no.second.erase(node.first);
                            }
                        }
                    }
                    nodes.erase(node.first);
                    break;
                }
            }
            if(!flag){
                return "";
            }
            if(result.length() == letter_num){
                break;
            }
        }
        return result;
    }
};