//Rotate the matrix to the right.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(v[i][j],v[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(v[i].begin(),v[i].end());
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

//time:O(n^2)
//space:O(1)
//Note : to rotate the matrix left , first take transpose and reverse all the columns .