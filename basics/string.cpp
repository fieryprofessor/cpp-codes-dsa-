//string
#include<bits/stdc++.h>
using namespace std;

int main(){
   string s = "Programming";
   int len = s.size();
   cout<<s[len-1]<<endl;
   // strings are mutable in c++ , therefore we can change individual characters.
   s[len-1] = 'o';
    cout<<s[len-1];
    return 0;
}