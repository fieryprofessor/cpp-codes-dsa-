//check if the number is a power of two.
#include<bits/stdc++.h>
using namespace std;

bool powerOfTwo( int &n){
    return n>0 && (n&(n-1))==0;
}

int main(){
    int n = 16;
    cout<<n<<endl;
    bool answer = powerOfTwo(n);
    cout<<answer;
    return 0;
}

//time:O(1)
//space:O(1)