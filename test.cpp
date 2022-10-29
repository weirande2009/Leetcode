#include <iostream>
using namespace std;


int main(){

    int a[50];
    for(int i=0; i<50; i++){
        a[i] = -1;
    }
    for(int i=1; i<=50; i++){
        for(int j=1; j<=50; j++){
            if(j % i == 0){
                a[j-1] *= -1;
            }
        }
    }
    int t = 0;
    for(int i=0; i<50; i++){
        if(a[i] == 1){
            t++;
        }
    }
    cout << t << endl;
    return 0;
}