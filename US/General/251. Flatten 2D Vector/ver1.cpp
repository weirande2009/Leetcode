#include <vector>
using namespace std;

class Vector2D {
public:
    vector<int> v;
    int p;
    int n;

    Vector2D(vector<vector<int>>& vec) {
        for(auto& ve: vec){
            for(auto& i: ve){
                v.push_back(i);
            }
        }
        p = 0;
        n = v.size();
    }
    
    int next() {
        return v[p++];
    }
    
    bool hasNext() {
        if(p == n){
            return false;
        }
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */