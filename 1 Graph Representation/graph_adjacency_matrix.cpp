#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    //declare the adjacency matrix
    int adj[n+1][n+1];

    //take edges as input
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u][v] = 1;
        adj[v][u] = 1;  //comment this (or line 18) for directed graph
    }
    
    return 0;
}