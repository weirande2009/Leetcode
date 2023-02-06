#include <bits/stdc++.h>
using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int dfs(unordered_map<int, Employee*>& employees, int id){
        int total = employees[id]->importance;
        for(int i: employees[id]->subordinates){
            total += dfs(employees, i);
        }
        return total;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*>hashtable;
        for(auto e: employees){
            hashtable[e->id] = e;
        }
        return dfs(hashtable, id);
    }
};