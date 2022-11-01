#include <string>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;



class WordDistance {
private:
    int n;
    unordered_map<string, int> hashtable;
    vector<int> words;
    
public:
    WordDistance(vector<string>& wordsDict) {
        n = wordsDict.size();
        words = vector<int>(n);
        int count = 0;
        for(int i=0; i<n; i++){
            if(hashtable.find(wordsDict[i]) == hashtable.end()){
                hashtable[wordsDict[i]] = count++;
            }
            words[i] = hashtable[wordsDict[i]];
        }
    }
    
    int shortest(string word1, string word2) {
        int a = hashtable[word1];
        int b = hashtable[word2];
        int left = -1;
        int right = -1;
        int cur = -1;
        int min_dis = INT_MAX;
        for(int i=0; i<n; i++){
            if(cur == -1){  // no word1 or word2 yet
                if(words[i] == a){  // find word1
                    left = i;
                    cur = 0;  // set now is word1
                }
                else if(words[i] == b){
                    right = i;
                    cur = 1;  // set now is word2
                }
            }
            else if(cur == 0){
                if(words[i] == a){  // find word1
                    left = i;  // update
                }
                else if(words[i] == b){  // find word2
                    right = i;
                    cur = 1;  // set now is word2
                    min_dis = min(min_dis, right-left);  // compute distance
                }
            }
            else if(cur == 1){
                if(words[i] == a){  // find word1
                    left = i;
                    cur = 0;  // set now is word1
                    min_dis = min(min_dis, left-right);  // compute distance
                }
                else if(words[i] == b){
                    right = i;  // udpate
                }
            }
        }
        return min_dis;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
