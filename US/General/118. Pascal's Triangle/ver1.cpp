#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        for(int i=1; i<numRows; i++){
            vector<int> tmp = {1};
            for(int j=1; j<i; j++){
                tmp.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }
        return result;
        
    }
};