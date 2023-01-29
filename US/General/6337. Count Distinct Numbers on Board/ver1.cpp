#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int distinctIntegers(int n) {
        unordered_set<int> board;
        board.insert(n);
        for(int i=0; i<1000000000; i++){
            unordered_set<int> tmp = board;
            for(int x: board){
                for(int j=1; j<=n; j++){
                    if(x % j == 1){
                        tmp.insert(j);
                    }
                }
            }
            bool over = true;
            if(tmp.size() != board.size()){
                over = false;
            }
            if(over){
                for(int x: tmp){
                    if(board.find(x) == board.end()){
                        over = false;
                        break;
                    }
                }
            }
            board = tmp;
            if(over){
                break;
            }
        }
        return board.size();
    }
};