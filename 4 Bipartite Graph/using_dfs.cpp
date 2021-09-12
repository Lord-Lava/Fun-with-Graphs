#include <iostream>
#include <vector>

using namespace std;

bool dfs_bipartite(int node,vector<int>adj[],vector<int>&col){
    for (auto it : adj[node])
    {
        if(col[it] == -1){
            col[it] = 1 - col[node];
            if(!dfs_bipartite(it,adj,col)) return false;
        }else if(col[it] == col[node]) return false;
    }
    return true;
}

bool isBipartite(int n,vector<int>adj[]){
    vector<int>col(n,-1);
    for (int i = 0; i < n; i++)
    {
        if(col[i] == -1){
            col[i] = 0;
            if(!dfs_bipartite(i,adj,col)) return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>adj[n];

    while(m--){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<isBipartite(n,adj)<<endl;

    return 0;
}