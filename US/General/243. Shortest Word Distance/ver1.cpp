#include <vector>
#include <limits.h>
#include <string>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> position1;
        vector<int> position2;
        int n = wordsDict.size();
        for(int i=0; i<n; i++){
            if(wordsDict[i] == word1){
                position1.push_back(i);
            }
        }
        for(int i=0; i<n; i++){
            if(wordsDict[i] == word2){
                position2.push_back(i);
            }
        }
        int dis = INT_MAX;
        for(int i=0; i<position1.size(); i++){
            for(int j=0; j<position2.size(); j++){
                dis = min(dis, abs(position1[i]-position2[j]));
            }
        }
        return dis;
    }
};