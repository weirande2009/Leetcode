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
    unordered_map<string, vector<int>> words_pos;
    
public:
    WordDistance(vector<string>& wordsDict) {
        n = wordsDict.size();
        words = vector<int>(n);
        int count = 0;
        for(int i=0; i<n; i++){
            if(hashtable.find(wordsDict[i]) == hashtable.end()){
                hashtable[wordsDict[i]] = count++;
                words_pos[wordsDict[i]] = vector<int>();
            }
            words[i] = hashtable[wordsDict[i]];
            words_pos[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        const vector<int>& word1_pos = words_pos[word1];
        const vector<int>& word2_pos = words_pos[word2];
        int n1 = word1_pos.size();
        int n2 = word2_pos.size();
        int min_dis = INT_MAX;
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                min_dis = min(min_dis, abs(word1_pos[i]-word2_pos[j]));
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