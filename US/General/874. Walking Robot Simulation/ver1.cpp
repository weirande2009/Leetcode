#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> hashtable;
        int mod = 3*10000+1;
        for(auto& v: obstacles){
            hashtable.insert(mod*v[1]+v[0]);
        }

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<int> pos = {0, 0};
        int directional = 0;
        int result = 0;
        for(int c: commands){
            if(c == -1){
                directional = (directional+1)%4;
            }
            else if(c == -2){
                directional = (directional-1+4)%4;
            }
            else{
                for(int i=0; i<c; i++){
                    int x = pos[0] + directions[directional][0];
                    int y = pos[1] + directions[directional][1];
                    if(hashtable.find(mod*x+y) != hashtable.end()){
                        break;
                    }
                    pos[0] = x;
                    pos[1] = y;
                }
                result = max(result, pos[0]*pos[0] + pos[1]*pos[1]);
            }
        }
        return result;
    }
};