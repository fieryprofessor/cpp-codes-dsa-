//if a zero is present in the matrix initially , set its row and column to zeros.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;

    for(int i=0;i<n;i++){
        vector<int>row;
        for(int j=0;j<m;j++){
            int ele;
            cin>>ele;
            row.push_back(ele);
        }
        v.push_back(row);
    }
    int col0 = v[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                v[i][0]=0;
                if(j!=0)
                    v[0][j]=0;
                else
                    col0=0;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(v[i][0]==0||v[0][j]==0){
                v[i][j]=0;
            }
        }
    }

    if(v[0][0]==0){
        for(int j=0;j<m;j++)
        v[0][j]=0;
    }
    if(col0==0){
        for(int i=0;i<n;i++)
        v[i][0]=0;
    }

    for(vector<int> vector :v){
        for(int ele: vector){
            cout<< ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}

//time: O(nm)
//space: O(1)