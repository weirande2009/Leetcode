#include <bits/stdc++.h>
using namespace std;


struct Interval{
    static int N;
    // both l and r are inclusive
    int l, r;
    Interval(int l, int r) : l(l), r(r) {}
    
    // get the max distance to the closest person
    int getDistance() const {
        if(l == 0)
            return r;
        if(r == N-1)
            return N-1-l;
        if(r < l)
            return -1;
        else
            return (r-l) / 2;
    }


    // get the position of the max distance to the closest person
    int getPosition() const {
        if(l == 0)
            return 0;
        if(r == N-1)
            return N-1;
        else
            return (l+r) / 2;
    }

    bool operator< (const Interval& rhs) const {
        if(this->getDistance() == rhs.getDistance()){
            return this->l < rhs.l;
        }
        else{
            return this->getDistance() > rhs.getDistance();
        }
    }
};

int Interval::N = 0;


class ExamRoom {
private:
    set<Interval> tab;
    // map the left side to right side in an inverval and right to left
    unordered_map<int, int> l2r, r2l;

public:
    ExamRoom(int n) {
        Interval::N = n;
        tab.insert(Interval(0, n-1));
        l2r[0] = n-1;
        r2l[n-1] = 0;
    }
    
    int seat() {
        // the target seat is seat of the first in set
        Interval st = *(tab.begin());
        // erase
        tab.erase(tab.begin());
        // get the position of the seat
        int pos = st.getPosition();
        // split the interval into two and insert
        tab.insert(Interval(st.l, pos-1));
        tab.insert(Interval(pos+1, st.r));
        // set map
        l2r[st.l] = pos-1;
        r2l[pos-1] = st.l;
        l2r[pos+1] = st.r;
        r2l[st.r] = pos+1;
        return pos;
    }
    
    void leave(int p) {
        // we know that there is an interval's right is p-1 and an interval's left is p+1
        int l = r2l[p-1];
        int r = l2r[p+1];
        // merge the two interval by first erase them and then insert a new one
        tab.erase(Interval(l, p-1));
        tab.erase(Interval(p+1, r));
        tab.insert(Interval(l, r));
        // update l2r and r2l
        l2r[l] = r;
        r2l[r] = l;
        l2r.erase(p+1);
        r2l.erase(p-1);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */