#include <vector>
using namespace std;

// Algorithm: O(nlogn)

class Solution {
public:
    long long ceiling(long long a, long long b){
        long long n = a / b;
        if(n*b == a){
            return n;
        }
        else{
            return n+1;
        }
    }
    
    // find whether the max number of number is feasible
    void dfs(vector<int>& quantities, int n, long long number, long long i, bool& ok){
        int m = quantities.size();
        if(i == m){
            ok = true;
            return;
        }
        long long k = ceiling(quantities[i], number);
        if(k > n){
            return;
        }
        else if(k == n){
            if(i == m-1){
                ok = true;
            }
            return;
        }
        dfs(quantities, n-k, number, i+1, ok);
    }
    
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        long long sum = 0;
        int mx = 0;
        for(int i=0; i<m; i++){
            sum += quantities[i];
            mx = max(mx, quantities[i]);
        }
        long long low = ceiling(sum, n);
        long long high = mx;
        // the answer must be between the avg of quantities and the max of quantities
        // use bianry search to find the answer 
        while(low < high){
            bool ok = false;
            long long mid = (low + high) / 2;
            dfs(quantities, n, mid, 0, ok);
            if(ok){
                high = mid-1;
            }
            else{
                low = mid+1;   
            }
        }
        bool ok = false;
        dfs(quantities, n, low, 0, ok);
        if(ok){
            return low;
        }
        else{
            return low+1;
        }
    }
};