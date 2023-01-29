#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    vector<int> v;
    // record the val and it's index in v
    unordered_map<int, int> hashtable;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        const auto it = hashtable.find(val);
        if(it != hashtable.end()){
            return false;
        }
        v.push_back(val);
        hashtable[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        const auto it = hashtable.find(val);
        if(it == hashtable.end()){
            return false;
        }
        // swap the val with the last in v
        v[hashtable[val]] = v.back();
        // update the index in hashtable
        hashtable[v[hashtable[val]]] = hashtable[val];
        // remove the last
        v.pop_back();
        // remove from the hashtable
        hashtable.erase(val);
        return true;
    }
    
    int getRandom() {
        int r = rand() % v.size();
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */