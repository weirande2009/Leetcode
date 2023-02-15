#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
private:
    vector<unordered_map<int, int>> arr;
    vector<vector<int>> snap_id_map;
    int snap_id;

public:
    SnapshotArray(int length) {
        arr = vector<unordered_map<int, int>>(length);
        snap_id_map = vector<vector<int>>(length, vector<int>(1, 0));
        snap_id = 0;
    }
    
    void set(int index, int val) {
        arr[index][snap_id] = val;
        if(snap_id_map[index].empty() || snap_id_map[index].back() != snap_id){
            snap_id_map[index].push_back(snap_id);
        }
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto it = lower_bound(snap_id_map[index].begin(), snap_id_map[index].end(),  snap_id);
        if(it != snap_id_map[index].end() && *it == snap_id){
            return arr[index][*it];
        }
        else{
            return arr[index][*(it-1)];
        }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */