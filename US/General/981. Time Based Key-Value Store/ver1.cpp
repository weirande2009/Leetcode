#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> hashtable;
    
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(hashtable.find(key) == hashtable.end()){
            hashtable[key].push_back(pair<string, int>{value, timestamp});
        }
        
        hashtable[key].push_back(pair<string, int>{value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(hashtable.find(key) == hashtable.end()){
            return "";
        }
        vector<pair<string, int>>& v = hashtable[key];
        if(timestamp < v[0].second){
            return "";
        }
        int n = v.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = (low+high) / 2;
            if(v[mid].second > timestamp){
                high = mid-1;
            }
            else if(v[mid].second < timestamp){
                low = mid+1;
            }
            else{
                low = mid;
                break;
            }
        }
        if(v[low].second > timestamp){
            low--;
        }
        return v[low].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

