#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

vector<int>shortest_path(int n,vector<pair<int,int>>adj[],int src){   //src is the starting/source node
    vector<int>dist(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    dist[src] = 0;
    pq.push({dist[src],src});

    while(!pq.empty()){
        pair<int,int> node = pq.top();
        pq.pop();

        for(auto it: adj[node.second]){
            if(node.first + it.second < dist[it.first]){
                dist[it.first] = node.first + it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    
    return dist;
}

int main(){
    int n,m,src;
    cin>>n>>m>>src;

    vector<pair<int,int>>adj[n+1];

    while(m--){
        int x,y,w;
        cin>>x>>y>>w;

        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    vector<int>ans = shortest_path(n,adj,src);

    for (int i = 1; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    

    return 0;
}