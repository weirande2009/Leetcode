#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> dfs(const string& s, int pos, int num){
        if(pos == s.length() || num == 0){
            return {};
        }
        vector<string> ans;
        if(s[pos] == '0'){
            if(pos == s.length()-1 && num == 1){
                ans.push_back("0");
            }
            else{
                vector<string> tmp = dfs(s, pos+1, num-1);
                if(tmp.size() != 0){
                    for(auto& t: tmp){
                        ans.push_back("0."+t);
                    }
                }
            }
        }
        else{
            if(s.length()-pos >= 3){
                int n = stoi(s.substr(pos, 3));
                if(n <= 255){
                    if(s.length()-pos == 3 && num == 1){
                        ans.push_back(s.substr(pos, 3));
                    }
                    else{
                        vector<string> tmp = dfs(s, pos+3, num-1);
                        if(tmp.size() != 0){
                            for(auto& t: tmp){
                                ans.push_back(s.substr(pos, 3)+"."+t);
                            }
                        }
                    }
                }
            }
            if(s.length()-pos > 2){
                vector<string> tmp = dfs(s, pos+2, num-1);
                if(tmp.size() != 0){
                    for(auto& t: tmp){
                        ans.push_back(s.substr(pos, 2)+"."+t);
                    }
                }
            }
            else if(s.length()-pos == 2 && num == 1){
                ans.push_back(s.substr(pos, 2));
            }
            if(s.length()-pos == 1 && num == 1){
                ans.push_back(s.substr(pos, 1));
            }
            else{
                vector<string> tmp = dfs(s, pos+1, num-1);
                if(tmp.size() != 0){
                    for(auto& t: tmp){
                        ans.push_back(s.substr(pos, 1)+"."+t);
                    }
                }
            }
        }
        return ans;
    }

    vector<string> restoreIpAddresses(string s) {
        return dfs(s, 0, 4);
    }
};