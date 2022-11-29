#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> hashtable;
        int count = 0;
        for(int t: time){
            if(hashtable.find(t%60) != hashtable.end()){
                count += hashtable[t%60];
            }
            hashtable[(60-(t%60))%60]++;
        }
        return count;
    }
};