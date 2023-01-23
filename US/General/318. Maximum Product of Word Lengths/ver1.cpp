#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        // in bit mask, the i-th bit corresponds to the i-th lowercase letter
        vector<int> bitmask(n);
        for(int i=0; i<n; i++){
            int mask = 0;
            for(char c: words[i]){
                mask |= 1 << (c-'a');
            }
            bitmask[i] = mask;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((bitmask[i]&bitmask[j]) == 0){
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return ans;
    }
};