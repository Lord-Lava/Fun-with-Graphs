#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool cycle_detect(int s,vector<int>vis,vector<int>adj[]){
    queue<pair<int,int>>q;
    q.push({s,-1});
    vis[s] = 1;
    
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto it: adj[node]){
            if(!vis[it]){
                q.push({it,node});
                vis[it] = 1;
            }
            else if(it!=par){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int n,vector<int>adj[]){
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycle_detect(i,vis,adj)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];

    while(m--){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<isCycle(n,adj)<<endl;

    return 0;
}