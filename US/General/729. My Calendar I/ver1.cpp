#include <vector>
#include <map>
using namespace std;

class MyCalendar {
private:
    map<int, int> hashmaps;

    bool intersected(int start1, int end1, int start2, int end2){
        return start1 < end2 && end1 > start2;
    }

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(hashmaps.size() == 0){
            hashmaps[start] = end;
            return true;
        }
        vector<pair<const int, int>> arr(hashmaps.begin(), hashmaps.end());
        if(arr.size() == 1){
            if(intersected(start, end, arr[0].first, arr[0].second)){
                return false;
            }
            else{
                hashmaps[start] = end;
                return true;
            }
        }
        if(start >= arr.back().second){
            hashmaps[start] = end;
            return true;
        }
        if(end <= arr.front().first){
            hashmaps[start] = end;
            return true;
        }
        int low = 0;
        int high = arr.size()-1;
        while(low < high){
            int mid = (low+high) / 2;
            if(arr[mid].first > start){
                high = mid-1;
            }
            else if(arr[mid].first < start){
                low = mid+1;
            }
            else{
                low = mid;
                break;
            }
        }
        if(low > 0){
            if(intersected(start, end, arr[low-1].first, arr[low-1].second)){
                return false;
            }
        }
        if(low < arr.size()-1){
            if(intersected(start, end, arr[low+1].first, arr[low+1].second)){
                return false;
            }
        }
        if(intersected(start, end, arr[low].first, arr[low].second)){
            return false;
        }
        else{
            hashmaps[start] = end;
            return true;
        }

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */