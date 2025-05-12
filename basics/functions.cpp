//functions
#include<bits/stdc++.h>
using namespace std;

int sum(int a, int b){
    return a+b;
}

void printer(int a, int b){
    cout<<a<<" "<<b;
}

int main(){
  int a,b;
  cin>>a>>b;
  int result = sum(a,b);
  cout<<result<<endl;
  printer(a,b);
  /*by default arguments are passed by value , if we want to pass them
  as a reference then add '&' before each parameter of the method*/
    return 0;
}