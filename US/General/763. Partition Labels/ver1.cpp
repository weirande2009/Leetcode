#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> record_last;
        int l = s.length();
        // record the last position of all characters
        for(int i=0; i<l; i++){
            record_last[s[i]] = i;
        }
        vector<int> result;
        int start = 0;
        int pos = 0;
        while(start < l){
            vector<char> char_in;
            int end = record_last[s[start]];
            while(pos < end){
                end = max(end, record_last[s[pos]]);
                pos++;
            }
            result.push_back(end-start+1);
            start = end+1;
        }
        return result;
    }
};