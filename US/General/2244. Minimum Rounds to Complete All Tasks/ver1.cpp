#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> counter;
        for(int t: tasks){
            counter[t]++;
        }
        int count = 0;
        for(auto& p: counter){
            if(p.second == 1){
                return -1;
            }
            else if(p.second < 4){
                count++;
            }
            else if(p.second % 3 == 0){
                count += p.second / 3;
            }
            else{
                count += p.second / 3 + 1;
            }
        }
        return count;
    }
};