#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

vector<int> prims_algo(int n,vector<pair<int,int>>adj[]){
    vector<int>parent(n,-1);
    vector<int>key(n,INT_MAX);
    //Note-> MST set is just used here for maintaining what all nodes have been included in the MST 
    //and does not actually help in the code (pq.pop() replacing its use) as in the brute force approach
    vector<bool>MST(n,false);

    key[0] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});

    for (int e = 0; e < n-1; e++)
    {
        int node = pq.top().second;;
        pq.pop();

        MST[node] = true;

        for(auto it:adj[node]){
            if(it.second < key[it.first]){
                key[it.first] = it.second;
                parent[it.first] = node;
                pq.push({key[it.first],it.first});
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