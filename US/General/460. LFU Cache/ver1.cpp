#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    // key of frequency and  value of a list of key-value pair that have the same frequency and the first is the least recently used
    unordered_map<int, list<pair<int, int>>> frequencies;
    // key of key and value of pair of frequency and the corresponding iterator in frequencies
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    // record the total capacity
    int capacity;
    // record the current minimum frequency
    int minf;

    void insert(int key, int value, int frequency){
        // add to frequencies
        frequencies[frequency].push_back({key, value});
        // set the iterator in cache
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()){  // don't find the key
            return -1;
        }
        // get the frequency of key
        const int f = it->second.first;
        // get the iterator in frequencies of key
        const auto iter = it->second.second;
        // get the key-value pair of the iterator
        const auto kv = *iter;
        // erase the frequency record in frequencies
        frequencies[f].erase(iter);
        // update the minimum frequency
        if(frequencies[f].empty() && minf == f){  // no more key use the minf, so we need to add one
            minf++;
        }
        // add the new frequency of the key-value pair to cache
        insert(kv.first, kv.second, f+1);
        return kv.second;
    }
    
    void put(int key, int value) {
        if(capacity <= 0){
            return;
        }
        const auto it = cache.find(key);
        if(it != cache.end()){
            // update the value
            it->second.second->second = value;
            // update the frequency
            get(key);
            return;
        }
        // if we don't find the key, this is a new key
        if(cache.size() == capacity){  // if the cache is full
            // we need to delete
            // remove from cache
            cache.erase(frequencies[minf].front().first);
            // remove from frequencies
            frequencies[minf].pop_front();
        }
        // the minf is reset to one
        minf = 1;
        // insert
        insert(key, value, 1);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */