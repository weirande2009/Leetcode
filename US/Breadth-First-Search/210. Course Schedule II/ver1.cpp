#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// The same as 207. The only difference in recursion function is that record the finished
// course. And record all courses without prerequisites at the beginning.

class Solution {
public:
    
    void Recursion(unordered_map<int, vector<int>>& hashtable, unordered_set<int>& route, int cur, bool& circle, unordered_set<int>& unfinished_set, vector<int>& result){
        if(route.find(cur) != route.end()){
            circle = true;
            return;
        }
        else{
            route.insert(cur);
            auto f = hashtable.find(cur);
            if(f != hashtable.end()){
                for(int i=0; i<f->second.size(); i++){
                    if(unfinished_set.find(f->second[i]) != unfinished_set.end())
                        Recursion(hashtable, route, f->second[i], circle,  unfinished_set, result);
                    if(circle){
                        return;
                    }
                }
            }
            unfinished_set.erase(cur);
            route.erase(cur);
            result.push_back(cur);
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> hashtable;
        unordered_set<int> unfinished_set;
        vector<int> result;
        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            if(hashtable.find(prerequisites[i][0]) != hashtable.end()){
                hashtable[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
            else{
                hashtable[prerequisites[i][0]] = vector<int>{prerequisites[i][1]};
            }
            unfinished_set.insert(prerequisites[i][0]);
        }
        for(int i=0; i<numCourses; i++){
            if(hashtable.find(i) == hashtable.end()){
                result.push_back(i);
            }
            else{
                unfinished_set.insert(i);
            }
        }
        unordered_set<int> finished_set;
        bool circle = false;
        while(!unfinished_set.empty()){
            unordered_set<int> route;
            Recursion(hashtable, route, *(unfinished_set.begin()), circle, unfinished_set, result);
            if(circle){
                break;
            }
        }
        if(circle)
            return {};
        else
            return result;
    }
};