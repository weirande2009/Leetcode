#include <vector>
using namespace std;

// Algorithm: O(n). First, check if there is an answer. If sum of gas >= sum of cost, there must
// be an answer. Then, add each dif to pre_fuel. If pre_fuel < 0, not enough fuel, reset pre_fuel
// and start. Because there must be an answer, we only need to have a loop.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> dif;        
        int total = 0;
        for(int i=0; i<n; i++){
            dif.push_back(gas[i] - cost[i]);
            total += dif[i];
        }
        if(total < 0){
            return -1;
        }
        int pre_fuel = 0;
        int start = 0;
        for(int i=0; i<n; i++){
            if(pre_fuel < 0){
                pre_fuel = 0;
                start = i;
            }
            pre_fuel += dif[i];
        }
        return start;
    }
};