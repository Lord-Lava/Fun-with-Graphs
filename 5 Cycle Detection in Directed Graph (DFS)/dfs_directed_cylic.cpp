#include <iostream>
#include <vector>

using namespace std;

bool isCycle_dfs(int node,vector<int>adj[],vector<int>vis,vector<int>dfs_vis){
    vis[node] = 1;
    dfs_vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(isCycle_dfs(it,adj,vis,dfs_vis)) return true;
        }else if(dfs_vis[it]){
            return true;
        }
    }
    dfs_vis[node] = 0;
    return false;
}

bool checkCycle(int n,vector<int> adj[]){
    vector<int>vis(n,0);
    vector<int>dfs_visited(n,0);

    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            if(isCycle_dfs(i,adj,vis,dfs_visited)) return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>adj[n];

    while(m--){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
    }

    cout<<checkCycle(n,adj)<<endl;

    return 0;
}