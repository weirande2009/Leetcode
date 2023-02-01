#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
private:
    queue<int> q;
    int size;
    double avg;
    int capacity;

public:
    MovingAverage(int size) {
        capacity = size;
        this->size = 0;
        this->avg = 0;
    }
    
    double next(int val) {
        if(this->size < this->capacity){
            q.push(val);
            avg = (avg*size+val) / (size+1);
            size++;
        }
        else{
            avg = (avg*size-q.front()+val) / size;
            q.pop();
            q.push(val);
        }
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */