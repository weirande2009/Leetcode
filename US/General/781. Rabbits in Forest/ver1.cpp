#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> hashtable;
        int count = 0;
        for(int answer: answers){
            hashtable[answer]++;
        }
        for(const pair<int, int>& p: hashtable){
            count += ceil((double)p.second / (p.first+1)) * (p.first+1);
        }


        return count;
    }
};