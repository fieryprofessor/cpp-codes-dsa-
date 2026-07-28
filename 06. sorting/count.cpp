#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &v){
    int n = v.size();

    int minEle = *min_element(v.begin(), v.end());
    int maxEle = *max_element(v.begin(),v.end());

    vector<int> count(maxEle-minEle+1,0);

    for(int i=0;i<n;i++){
        count[v[i]-minEle]++;
    }

    for(int i=1;i<=maxEle;i++){
        count[i] += count[i-1];
    }

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[count[v[i]-minEle] - 1] = v[i];
        count[v[i]-minEle]--;
    }

    for(int i=0;i<n;i++){
        v[i] = ans[i];
    } 
}

int main(){
    vector<int> v={4,2,3,1,5};
    countSort(v);
    for(auto ele: v){
        cout<<ele<<" ";
    }
    return 0;
}

/*
 * Time Complexity = O(n+m)
 * Space Complexity = O(n+m)
 * Stable Sorting = Yes
 */
