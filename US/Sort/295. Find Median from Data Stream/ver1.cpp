#include <queue>
using namespace std;

// Algorithm: O(logn) in add and O(1) in find. Use two priority queue to store the larger
// and smaller part. And smaller one is 1 longer than larger one. To get the smallest number
// in larger one, we store -num in it. 

class MedianFinder {
private:
    priority_queue<int> large;
    priority_queue<int> small;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n_l = large.size();
        int n_s = small.size();
        if(n_s == 0){
            small.push(num);
        }
        else if(n_l == n_s){
            if(-large.top() >= num){
                small.push(num);
            }
            else{
                small.push(-large.top());
                large.pop();
                large.push(-num);
            }
        }
        else{
            if(small.top() > num){
                large.push(-small.top());
                small.pop();
                small.push(num);
            }
            else{
                large.push(-num);
            }
        }
    }
    
    double findMedian() {
        int n_l = large.size();
        int n_s = small.size();
        if(n_l == n_s){
            return (small.top()-large.top()) / 2.0;
        }
        else{
            return small.top();
        }
    }
};

