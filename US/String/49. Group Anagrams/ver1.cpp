#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Algorithm: O(n^2logn). For each str, sort it, if str consist of the same words, after sorting,
// the string will be the same. So we use a unordered_map to store the group index of sorted str.
// After sorting, we find the sorted str in map, if find, add to the existing group. If not find,
// create a new group.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> record;
        for(int i=0; i<strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            auto f = record.find(tmp);
            if(f == record.end()){
                record[tmp] = result.size();
                vector<string> new_group;
                new_group.push_back(strs[i]);
                result.push_back(new_group);
            }
            else{
                result[record[tmp]].push_back(strs[i]);
            }    
        }
        return result;
        
    }
};

int main()
{
    string s = "54312";
    sort(s.begin(), s.end());
    cout << s << endl;

    return 0;

}


