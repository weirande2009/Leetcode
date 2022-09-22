#include <vector>
#include <unordered_set>
using namespace std;

class A{
public:
    int x;
    A(int _x) : x(_x) {}
};

int main(){
    vector<A> a;
    unordered_set<A> b;
    return 0;
}