#include <bits/stdc++>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.length();
        stack<string> ss;
        stack<int> ls;
        string cur;
        long long count = 0;
        for(int i=0; i<n; i++){
            if(s[i] >= '2' && s[i] <= '9'){
                int time = s[i] - '0';
                count *= time;
                ss.push(cur);
                ls.push(time);
                cur = "";
                if(count >= k){
                    k--;
                    while(1){
                        count /= ls.top();
                        int pos = k % count;
                        if(pos >= count - ss.top().length()){  // target is in the newly added string
                            return string(1, ss.top()[pos-(count - ss.top().length())]);
                        }
                        else{
                            count -= ss.top().length();
                            k = pos;
                            ss.pop();
                            ls.pop();
                        }
                    }
                }
            }
            else{
                cur += string(1, s[i]);
                count++;
                if(count == k){
                    return string(1, s[i]);
                }
            }
        }
        return 0;
    }
};