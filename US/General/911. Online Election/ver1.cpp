#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
private:
    vector<pair<int, int>> winners;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int max_vote = 0;
        int n = persons.size();
        unordered_map<int, int> votes;
        for(int i=0; i<n; i++){
            votes[persons[i]]++;
            if(votes[persons[i]] >= max_vote){
                max_vote = votes[persons[i]];
                winners.push_back({times[i], persons[i]});
            }
        }
    }
    
    int q(int t) {
        pair<int, int> target = {t, 1000000001};
        auto it = upper_bound(winners.begin(), winners.end(), target);
        return (it-1)->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */