#include <iostream>
#include <vector>

using namespace std;

bool cycleDfs(int node,vector<int>adj[],int par,vector<int>&vis){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(cycleDfs(it,adj,node,vis)){
                return true;
            }
        } else if(it != par) return true;
    }
    return false;
}

bool isCycle(int n,vector<int>adj[]){
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycleDfs(i,adj,-1,vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    while(m--){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<isCycle(n,adj)<<endl;

    return 0;
}