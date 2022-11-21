#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i=0; i<n; i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            y -= x;
            if(y > 0){
                pq.push(y);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};