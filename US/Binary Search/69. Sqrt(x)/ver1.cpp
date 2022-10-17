
class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;
        while(low < high){
            long long mid = (low+high) / 2;
            if(mid*mid < x){
                low = mid+1;
            }
            else if(mid*mid > x){
                high = mid-1;
            }
            else{
                return mid;
            }
        }
        if(low*low > x){
            return low-1;
        }
        else{
            return low;
        }
    }
};