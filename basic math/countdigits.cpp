//count the number of digits in a number
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 7549;
    int c2 = (int)log10(n)+1; //logarithmic formula takes O(1) time.
    int c = 0;
    while(n>0){
        int d = n%10;
        c++;
        n = n/10;
    }
    cout<<c<<endl;
    cout<<c2<<endl;
    return 0;
}