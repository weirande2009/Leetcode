#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<unordered_set<char>> pool;
        // generate cluster
        for(int i=0; i<s1.length(); i++){
            vector<int> pool_i;
            for(int j=0; j<pool.size(); j++){
                if(pool[j].find(s1[i]) != pool[j].end() || pool[j].find(s2[i]) != pool[j].end()){
                    pool_i.push_back(j);
                }
            }
            if(pool_i.size() != 0){
                // combine to the first
                int pivot = pool_i[0];
                for(int j=1; j<pool_i.size(); j++){
                    for(char c: pool[pool_i[j]]){
                        pool[pivot].insert(c);
                    }
                }
                for(int j=1; j<pool_i.size(); j++){
                    pool.erase(pool.begin()+pool_i[j]-j+1);
                }
                // add to the pivot
                pool[pivot].insert(s1[i]);
                pool[pivot].insert(s2[i]);
            }
            else{
                pool.push_back(unordered_set<char>());
                pool[pool.size()-1].insert(s1[i]);
                pool[pool.size()-1].insert(s2[i]);
            }
        }
        // generate the lowest char for each character
        unordered_map<char, char> hashtable;
        for(auto& s: pool){
            char m = CHAR_MAX;
            for(char c: s){
                m = min(m, c);
            }
            for(char c: s){
                hashtable[c] = m;
            }
        }
        string result;
        // generate result by the hashtable
        for(char c: baseStr){
            if(hashtable.find(c) != hashtable.end()){
                result += hashtable[c];
            }
            else{
                result += c;
            }
        }
        return result;
    }
};