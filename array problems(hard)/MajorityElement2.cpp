//give all the elements which appear more than n/3 times in the array.
#include<bits/stdc++.h>
using namespace std;

void majorityElements(vector<int>&v){
    int ele1=-1,ele2=-1;
    int c1=0,c2=0;
    for(int i=0;i<v.size();i++){
         if (v[i] == ele1) {
            c1++;
        } else if (v[i] == ele2) {
            c2++;
        } else if (c1 == 0) {
            ele1 = v[i];
            c1 = 1;
        } else if (c2 == 0) {
            ele2 = v[i];
            c2 = 1;
        } else {
            c1--;
            c2--;
        }
    }

    c1 = c2 = 0;
    for (int num : v) {
        if (num == ele1) c1++;
        else if (num == ele2) c2++;
    }
    if (c1 > v.size() / 3)cout<<ele1<<" ";
    if (c2 > v.size() / 3)cout<<ele2;
}

int main(){
    vector<int>v={2,1,1,3,1,4,5,6};
    majorityElements(v);
    return 0;
}