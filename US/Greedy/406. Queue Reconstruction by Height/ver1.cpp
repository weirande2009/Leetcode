#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// Algorithm: O(nlogn). Sort the array as descending on p[0] and ascending on p[1].
// New a list, insert the p[i] in to list[p[i][1]].



class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](vector<int> v1, vector<int> v2){
            if(v1[0] > v2[0]){
                return true;
            }
            else if(v1[0] < v2[0]){
                return false;
            }
            else{
                return v1[1] < v2[1];
            }
        });
        list<vector<int>> result;
        for(auto p: people){
            auto it = result.begin();
            for(int i=0; i<p[1]; i++){
                it++;
            }
            result.insert(it, p);
        }
        
        return vector<vector<int>>(result.begin(), result.end());
    }
};