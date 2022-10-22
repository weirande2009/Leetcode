
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long low = 1;
        long long high = n;
        while(low < high){
            long long mid = (low+high)/2;
            if(isBadVersion(mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};