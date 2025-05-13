//maximum and minimum elements in the array
#include<bits/stdc++.h>
using namespace std;

int main(){
   int arr[] = {1,2,3,4,5};
   int maxele = *max_element(arr,arr+5);
   int minele = *min_element(arr,arr+5);
   cout<<maxele<<endl;
   cout<<minele<<endl;
    return 0;
}