#include <iostream>
#include <climits>
#include <vector>

using namespace std;

vector<int> prims_algo(int n,vector<pair<int,int>>adj[]){
    vector<int>parent(n,-1);
    vector<int>key(n,INT_MAX);
    vector<bool>MST(n,false);

    key[0] = 0;

    for (int i = 0; i < n-1; i++)
    {
        int mini = INT_MAX;
        int node;

        for (int i = 0; i < n; i++)
        {
            if(!MST[i] && key[i]<mini){
                mini = key[i];
                node = i;
            }    
        }

        MST[node] = true;

        for(auto it: adj[node]){
            if(it.second<key[it.first]){
                key[it.first] = it.second;
                parent[it.first] = node;
            }
        }
    }
    return parent;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>adj[n];

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int>parent = prims_algo(n,adj);

    for(int i=1;i<parent.size();i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }

    return 0;
}

/*
Input 1->
5 6
0 1 2
0 3 6
1 2 3 
1 3 8
2 4 7
4 1 5

Output 1->
0 - 1
1 - 2
0 - 3
1 - 4

Input 2->
6 9
0 1 2
0 3 8
0 4 4
1 2 3
1 3 3 
1 5 7
2 3 5
2 5 8
3 4 9

Output 2->
0 - 1
1 - 2
1 - 3
0 - 4
1 - 5
*/