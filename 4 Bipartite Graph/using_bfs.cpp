#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs_Bipartite(int node,vector<int> adj[],vector<int> &col){
    queue<int>q;
    q.push(node);
    col[node] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(auto it:adj[par]){
            if(col[it] == -1){
                col[it] = 1-col[par];
                q.push(it);
            }else if(col[it] == col[par]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<int>adj[],int n){
    vector<int>col(n,-1);
    for(int i=0;i<n;i++){
        if(col[i] == -1){
            if(!bfs_Bipartite(i,adj,col)){
                return false;
            }
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

    cout<<isBipartite(adj,n)<<endl;

    return 0;
}

//1-based (not-bipartite)
//8 8
// 1 2
// 2 3 
// 2 8
// 3 4
// 4 5
// 5 6
// 5 8
// 6 7