#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s;
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
        while(pq.size() > 1){
            auto one = pq.top();
            pq.pop();
            auto two = pq.top();
            pq.pop();
            if(one.first >= 2){
                s += string(1, one.second);
                s += string(1, one.second);
                one.first -= 2;
            }
            else if(one.first == 1){
                s += string(1, one.second);
                one.first -= 1;
            }

            if(two.first >= 2 && two.first >= one.first){
                s += string(1, two.second);
                s += string(1, two.second);
                two.first -= 2;
            }
            else{
                s += string(1, two.second);
                two.first -= 1;
            }

            if(one.first > 0){
                pq.push(one);
            }
            if(two.first > 0){
                pq.push(two);
            }
        }
        if(pq.empty()){
            return s;
        }
        if(pq.top().first >= 2){
            s += string(1, pq.top().second);
            s += string(1, pq.top().second);
        }
        else if(pq.top().first == 1){
            s += string(1, pq.top().second);
        }

        return s;
    }
};