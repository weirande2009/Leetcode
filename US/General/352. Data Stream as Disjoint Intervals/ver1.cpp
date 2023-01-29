#include <vector>
#include <set>
using namespace std;

class SummaryRanges {
private:
    set<int> record;

public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        record.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        vector<int> stream(record.begin(), record.end());
        int begin = 0;
        for(int i=1; i<stream.size(); i++){
            if(stream[i] == stream[i-1]){
                continue;
            }
            if(stream[i]-stream[i-1] != 1){
                ans.push_back({stream[begin], stream[i-1]});
                begin = i;
            }
        }
        ans.push_back({stream[begin], stream.back()});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */