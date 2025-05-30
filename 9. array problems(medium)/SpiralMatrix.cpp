//Print the matrix in a spiral order.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    int top=0;
    int right= m-1;
    int bottom = n-1;
    int left = 0;

    while(top<=bottom && left<=right){

        for(int i=left;i<=right;i++)
            cout<<v[top][i]<<" ";
        top++;
        
        for(int i=top;i<=bottom;i++)
            cout<<v[i][right]<<" ";
        right--;
        
        if(top<=bottom){
            for(int i=right;i>=left;i--)
                cout<<v[bottom][i]<<" ";
            bottom--;
        }
        
        if(left<=right){
            for(int i=bottom;i>=top;i--)
                cout<<v[i][left]<<" ";
            left++;
        }
        
    }

    return 0;
}

//time: O(nm)
//space: O(1)