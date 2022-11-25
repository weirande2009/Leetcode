#include <vector>
using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        for(int i=1; i<=rowIndex; i++){
            vector<int> tmp = {1};
            for(int j=1; j<i; j++){
                tmp.push_back(result[j-1]+result[j]);
            }
            tmp.push_back(1);
            result = tmp;
        }
        return result;
    }
};
