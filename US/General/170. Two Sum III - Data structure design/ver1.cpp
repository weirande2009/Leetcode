#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class TwoSum {
public:
    vector<int> nums;
    unordered_set<int> record;

    TwoSum() {
        
    }
    
    void add(int number) {
        nums.push_back(number);
    }
    
    bool find(int value) {
        if(record.find(value) != record.end()){
            return true;
        }
        int n = nums.size();
        if(n < 2){
            return false;
        }
        unordered_map<int, int> hashtable;
        for(int i=0; i<n; i++){
            hashtable[value-nums[i]] = i;
        }
        for(int i=0; i<n; i++){
            if(hashtable.find(nums[i]) != hashtable.end() && hashtable[nums[i]] != i){
                record.insert(value);
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */