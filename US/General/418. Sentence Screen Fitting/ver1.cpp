#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> nums(n, 0);
        for(int i=0; i<n; i++){
            nums[i] = sentence[i].length();
            if(nums[i] > cols){
                return 0;
            }
        }
        int times = 0;
        int row = 0;
        // dp[i] means the state of start a new setence at index of i
        // dp[i][0] means the next word index, dp[i][1] means times
        vector<vector<int>> dp(n, vector<int>{-1, 0});
        int i=0;
        while(row < rows){
            if(dp[i][0] != -1){
                times += dp[i][1];
                i = dp[i][0];
            }
            else{
                int count = 0;
                int col = 0;
                int start_i = i;
                while(col+nums[i] <= cols){
                    col += nums[i]+1;
                    i++;
                    if(i >= n){
                        i = 0;
                        count++;
                    }
                }
                dp[start_i] = {i, count};
                times += count;
            }
            row++;
        }
        return times;
    }
};
