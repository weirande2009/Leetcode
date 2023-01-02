#include <vector>
using namespace std;

class Solution {
private:

public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n, 0);
        for(auto& booking: bookings){
            // only add to the first flight
            seats[booking[0]-1] += booking[2];
            // remove at the next flight after booking[1]
            if(booking[1] < n){
                seats[booking[1]] -= booking[2];
            }
        }
        // cumulative sum is just the answer
        for(int i=1; i<n; i++){
            seats[i] += seats[i-1];
        }
        return seats;
    }
};