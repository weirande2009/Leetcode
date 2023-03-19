#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> record(n);
        for(int i=0; i<n; i++){
            vector<int> invalid;
            for(int j=0; j<i; j++){
                if(nums[j] + k == nums[i]){
                    invalid.push_back(j);
                    cout << j << endl;
                }
                else if(nums[j] + k > nums[i]){
                    break;
                }
            }
            for(int j=0; j<i; j++){
                if(nums[j] + k == nums[i]){
                    continue;
                }
                else if(nums[j] > nums[i] - k){
                    for(int k=0; k<record[j].size(); k++){
                        bool ok = true;
                        for(int l=0; l<invalid.size(); l++){
                            if((record[j][k] & (1 << invalid[l])) != 0){
                                ok = false;
                                break;
                            }
                        }
                        if(ok){
                            count++;
                            record[i].push_back(record[j][k] | (1 << i));
                        }
                    }
                }
                else{
                    for(int k=0; k<record[j].size(); k++){
                        count++;
                        record[i].push_back(record[j][k] | (1 << i));
                    }
                }
            }
            record[i].push_back(1 << i);
            count++;
        }
        return count;
    }
};