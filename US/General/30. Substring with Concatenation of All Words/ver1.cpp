#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void resetCounts(vector<int>& counts, unordered_map<string, int>& hashtable, vector<string>& words){
        int n = words.size();
        for(int& c: counts){
            c = 0;
        }
        for(int i=0; i<n; i++){
            counts[hashtable[words[i]]]++;
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int l = words[0].length();
        int n = words.size();
        vector<int> counts(n, 0);
        unordered_map<string, int> hashtable;
        for(int i=0; i<n; i++){
            if(hashtable.find(words[i]) == hashtable.end()){
                hashtable[words[i]] = i;
            }
            counts[hashtable[words[i]]]++;
        }
        // find all that match a word
        vector<vector<int>> record;  // the first is pos, the second is index in counts
        for(int i=0; i<s.length()-l+1; i++){
            const auto& f = hashtable.find(s.substr(i, l));
            if(f != hashtable.end()){
                record.push_back({i, f->second});
            }
        }
        vector<int> result;
        for(int i=0; i<record.size()-n+1; i++){
            // check whether the distance of each word is l
            vector<int> record_i = {i};
            for(int j=i+1, c=1; j<record.size(); j++, c++){
                if(record[j][0]-record[i][0] == c*l){
                    // record the next possible start
                    record_i.push_back(j);
                    if(record_i.size() == n){
                        break;
                    }
                }
                else{
                    c--;
                }
            }
            if(record_i.size() == n){
                // check in counts
                for(int j=0; j<n; j++){
                    counts[record[record_i[j]][1]]--;
                }
                bool flag = true;
                for(int count: counts){
                    if(count != 0){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    result.push_back(record[i][0]);
                }
                resetCounts(counts, hashtable, words);
            }
        }
        return result;
    }
};