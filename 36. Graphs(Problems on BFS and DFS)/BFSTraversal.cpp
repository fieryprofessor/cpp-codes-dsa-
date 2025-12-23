//Breadth first search of a given graph.
#include<bits/stdc++.h>
using namespace std;

vector<int> bfstraversal(int v, vector<int>adj[]){
    vector<int>bfs;
    vector<bool>visited(v+1,false);
    queue<int>q;
    visited[1]=true;
    q.push(1);
    while(!q.empty()){
        int currentVertex = q.front();
        q.pop();
        bfs.push_back(currentVertex);
        for(auto i: adj[currentVertex]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return bfs;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = bfstraversal(n,adj);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}

//time: O(n+2e) where n is number of nodes and e is number of edges.
//space: O(n) for queue and visited array.