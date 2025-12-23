//Depth first search of a given graph.
#include<bits/stdc++.h>
using namespace std;

void dfsfun(int val, vector<int>adj[],vector<bool>&visited,vector<int>&dfs){
    visited[val]=true;
    dfs.push_back(val);
    for(auto i: adj[val]){
        if(!visited[i])
        dfsfun(i,adj,visited,dfs);
    }
}

vector<int> dfstraversal(int v, vector<int>adj[]){
    vector<int>dfs;
    vector<bool>visited(v+1,false);
    dfsfun(1,adj,visited,dfs);
    return dfs;
}

vector<int> dfstraversal_iterative(int v, vector<int> adj[]) {
    vector<int> dfs;
    vector<bool> visited(v + 1, false);
    stack<int> s;

    s.push(1);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            dfs.push_back(current);

            for (auto i : adj[current]) {
                if (!visited[i])
                    s.push(i);
            }
        }
    }
    return dfs;
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
    vector<int> ans = dfstraversal(n,adj);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}

//time: O(n+2e) where n is number of nodes and e is number of edges.
//space: O(n) for queue and visited array.