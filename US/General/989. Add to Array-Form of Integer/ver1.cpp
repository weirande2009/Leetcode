#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        // convert k to an array
        string ks = to_string(k);
        vector<int> knum(ks.length());
        for(int i=0; i<ks.length(); i++){
            knum[i] = ks[i]-'0';
        }
        int i = num.size()-1;
        int j = knum.size()-1;
        int carry = 0;
        vector<int> ans;
        while(1){
            int sum = carry;
            if(i >= 0){
                sum += num[i--];
            }
            if(j >= 0){
                sum += knum[j--];
            }
            if(sum >= 10){
                carry = 1;
                sum -= 10;
            }
            else{
                carry = 0;
            }
            ans.push_back(sum);
            if(i < 0 && j < 0 && carry == 0){
                break;
            }
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};