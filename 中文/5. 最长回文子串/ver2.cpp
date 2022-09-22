#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    利用动态规划的算法进行解题
    1、将题目的大问题分解为多个小问题
    2、对于每个小问题寻找递推公式，并将每个小问题的状态记录到表中
    3、根据表中记录的状态一步步地得到所有的状态
    4、设置好边界条件，在递推到边界时需要有确定的状态
    5、在递推时，使用确定的状态以及递推公式，来得到其他的状态
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2){  // 若串长小于2，则直接返回
            return s;
        }

        int max_length = 1;
        int begin_pos = 0;
        // 定义一个n×n的二维数组，其中record[i][j]表示，s[i:j+1]是否为回文串
        vector<vector<int>> record(n, vector<int>(n));
        // 单个字符永远为回文串
        for(int i=0; i<n; i++){
            record[i][i] = true;
        }
        // 开始递归
        for(int L=2; L<=n; L++){  // L表示当前的判断的串的长度
            for(int i=0; i<n; i++){  // i表示当前判断的串的起始下标
                int j = i + L - 1;  // j表示当前判断的串的结尾下标
                if(j >= n){  // 若结尾下标越界，则直接返回
                    break;
                }
                if(s[i] != s[j]){  // 若当前判断的串的首尾不相同，则s[i:j+1]必不可能是回文串
                    record[i][j] = false;
                }
                else{  // 若当前判断的串的首尾相同
                    if(j - i < 3){  // 若当前判断的串的长度为3,2或1，则可以直接确定该串为回文串
                        record[i][j] = true;
                    }
                    else{  // 若当前判断的串的长度大于3，则record[i][j]是否为回文串，则由record[i+1][j-1]决定
                        // s[i+1:j-1]的长度比s[i:j]短，因此此时s[i+1:j-1]的是否为回文串是已知的
                        record[i][j] = record[i+1][j-1];
                    }
                }
                if(record[i][j] && L > max_length){  // 若当前判断的是回文串，且长度大于记录的最长串，则记录该串
                    max_length = L;
                    begin_pos = i;
                }
            }
        }
        return s.substr(begin_pos, max_length);
    }
};