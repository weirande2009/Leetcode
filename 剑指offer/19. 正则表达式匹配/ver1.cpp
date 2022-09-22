#include <string>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int p_i = 0;
        int s_i = 0;
        int p_n = p.length();
        int s_n = s.length();
        vector<char> stars;
        while(1){
            if(p[p_i] == '.'){
                if(p_i + 1 < p_n){
                    if(p[p_i+1] == '*'){
                        // Add all to record
                        for(int i=s_i; i< s_n; i++){
                            stars.push_back(s[i]);
                            s_i++;
                        }
                        p_i++;
                    }
                    else{
                        if(stars.size() > 0){
                            stars.erase(stars.begin()+stars.size()-1);
                        }
                        else{
                            s_i++;
                            if(s_i >= s_n){
                                return false;
                            }
                        }
                    }
                }
                else{
                    if(p_i == p_n - 1){
                        
                    }

                    if(stars.size() > 0){
                        stars.erase(stars.begin()+stars.size()-1);
                    }
                    else{
                        s_i++;
                        if(s_i >= s_n){
                            return false;
                        }
                    }
                }
            }
            else{
                // The next one is '*'
                bool pattern_star = false;
                if(p_i + 1 < p_n){
                    if(p[p_i+1] == '*'){
                        pattern_star = true;
                    }
                }
                if(pattern_star){
                    // Get from last star
                    vector<char> tmp_star_vector;
                    int stars_size = stars.size();
                    while(1){
                        int n = stars.size();
                        if(n <= 0){
                            break;
                        }
                        if(stars[n-1] == p[p_i]){
                            tmp_star_vector.insert(tmp_star_vector.begin(), p[p_i]);
                            stars.erase(stars.begin()+n-1);
                        }
                        else{
                            break;
                        }
                    }
                    while(s[s_i] == p[p_i]){
                        tmp_star_vector.push_back(p[p_i]);
                        s_i++;
                        if(s_i >= s_n){
                            break;
                        }
                    }
                    // Record star
                    if(tmp_star_vector.size() > 0){
                        stars = tmp_star_vector;
                    }
                    p_i++;
                }
                else{
                    // First check whether is star
                    if(stars.size() > 0){
                        if(p[p_i] == stars[stars.size()-1]){
                            stars.erase(stars.begin()+stars.size()-1);
                        }
                        else{
                            if(s[s_i] == p[p_i]){
                                stars.clear();
                                s_i++;
                            }
                            else{
                                return false;
                            }
                        }
                    }
                    else{
                        if(s[s_i] == p[p_i]){
                            stars.clear();
                            s_i++;
                        }
                        else{
                            return false;
                        }
                    }
                    
                }
            }
            p_i++;
            if(s_i >= s_n && p_i >= p_n){
                return true;
            }
            if(s_i >= s_n || p_i >= p_n){
                
            }
        }
    }
};

int main(){
    string s = "mississippi";
    string p = "mis*is*ip*.";
    Solution solution;
    solution.isMatch(s, p);
    return 0;
}