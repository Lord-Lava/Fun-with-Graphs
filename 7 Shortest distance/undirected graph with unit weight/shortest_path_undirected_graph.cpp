#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

vector<int>shortest_path(int n,vector<int>adj[],int src){   //src is the starting/source node
    queue<int>q;
    vector<int>dist(n,INT_MAX);

    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }
    
    return dist;
}

int main(){
    int n,m,src;
    cin>>n>>m>>src;

    vector<int>adj[n];

    while(m--){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>ans = shortest_path(n,adj,src);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    

    return 0;
}