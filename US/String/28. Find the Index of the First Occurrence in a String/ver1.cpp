#include <vector>
#include <string>
using namespace std;

// Algorithm: O(n), traverse string and when haystack[i] == needle[0], start comparing
// and in this process record the fisrt index j>i that haystack[j] == needle[0].
// When this comparison fail, use the index j as the next index in the loop.


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m > n){
            return -1;
        }
        int next_first_pos;
        bool find_next_first = false;
        bool start_comparing = false;
        int n_pos = 0;
        for(int i=0; i<n; i++){
            if(start_comparing && !find_next_first && haystack[i] == needle[0]){
                next_first_pos = i;
                find_next_first = true;
            }
            if(haystack[i] == needle[n_pos]){
                start_comparing = true;
                n_pos++;
                if(n_pos == m){
                    return i-n_pos+1;
                }
            }
            else{
                if(find_next_first){
                    i = next_first_pos - 1;
                    find_next_first = false;
                }
                start_comparing = false;
                n_pos = 0;
            }
        }
        return -1;
    }
};