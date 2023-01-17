#include <vector>
using namespace std;

class HitCounter {
private:
    vector<int> history;

public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        history.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int count = 0;
        for(int i=history.size()-1; i>=0; i--){
            if(history[i] <= timestamp){
                if(timestamp-history[i] < 300){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */