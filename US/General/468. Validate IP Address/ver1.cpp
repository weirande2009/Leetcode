#include <string>
using namespace std;


class Solution {
public:
    string validIPAddress(string queryIP) {
        bool ipv4 = true;
        int n = queryIP.length();
        for(int i=0; i<n; i++){
            if(queryIP[i] == '.'){
                break;
            }
            else if(queryIP[i] == ':'){
                ipv4 = false;
                break;
            }
        }
        if(ipv4){
            int begin = 0;
            queryIP += '.';
            int count = 0;
            for(int i=0; i<n+1; i++){
                if(queryIP[i] == '.'){
                    count++;
                    if(count == 4 && i != n){
                        return "Neither";
                    }
                    if(i == begin){
                        return "Neither";
                    }
                    else if(queryIP[begin] < '0' || queryIP[begin] > '9'){
                        return "Neither";
                    }
                    else if(queryIP[begin] == '0' && i-begin > 1){
                        return "Neither";
                    }
                    else if(i-begin > 3 || i-begin == 3 && queryIP[begin] > '2'){
                        return "Neither";
                    }
                    else{
                        int num = stoi(queryIP.substr(begin, i-begin));
                        if(num > 255){
                            return "Neither";
                        }
                    }
                    begin = i+1;
                }
                else{
                    if(queryIP[i] < '0' || queryIP[i] > '9'){
                        return "Neither";
                    }
                }
            }
            if(count != 4){
                return "Neither";
            }
            return "IPv4";
        }
        else{
            int begin = 0;
            queryIP += ':';
            int count = 0;
            for(int i=0; i<n+1; i++){
                if(queryIP[i] == ':'){
                    count++;
                    if(count == 8 && i != n){
                        return "Neither";
                    }
                    if(i == begin){
                        return "Neither";
                    }
                    else if(i-begin > 4){
                        return "Neither";
                    }
                    begin = i+1;
                }
                else{
                    if(!(queryIP[i] >= 'a' && queryIP[i] <= 'f' || queryIP[i] >= 'A' && queryIP[i] <= 'F'|| queryIP[i] >= '0' && queryIP[i] <= '9')){
                        return "Neither";
                    }
                }
            }
            if(count != 8){
                return "Neither";
            }
            return "IPv6";
        }
    }
};