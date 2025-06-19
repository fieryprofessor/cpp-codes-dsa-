//Remove the last set bit from the number.
#include<bits/stdc++.h>
using namespace std;

void removeLastSetBit( int &n){
    n = n & (n-1);
}

int main(){
    int n = 13;
    cout<<n<<endl;
    removeLastSetBit(n);
    cout<<n;
    return 0;
}

//time:O(1)
//space:O(1)