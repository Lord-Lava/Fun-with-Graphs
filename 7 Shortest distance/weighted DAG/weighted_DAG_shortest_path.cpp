#include <iostream>
#include <climits>
#include <stack>
#include <vector>

using namespace std;

void find_topo_sort(int node,vector<int>&vis,stack<int>&st,vector<pair<int,int>>adj[]){
    vis[node] = 1;

    for (auto it :adj[node])
    {
        if(!vis[it.first]){
            find_topo_sort(it.first,vis,st,adj);
        }
    }
    st.push(node);
}

vector<int>shortest_path(int n,vector<pair<int,int>>adj[],int src){   //src is the starting/source node
    vector<int>vis(n,0);
    stack<int>st;

    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            find_topo_sort(i,vis,st,adj);
        }
    }
    
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dist[node]!=INT_MAX){        //if node has been reached previously
            for(auto it: adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    return dist;
}

int main(){
    int n,m,src;
    cin>>n>>m>>src;

    vector<pair<int,int>>adj[n];

    while(m--){
        int x,y,w;
        cin>>x>>y>>w;

        adj[x].push_back({y,w});
    }

    vector<int>ans = shortest_path(n,adj,src);

    for (int i = 0; i < ans.size(); i++)
    {
        if(ans[i] == INT_MAX)
            cout<<"INF ";   //inf signifies unreachable nodes here
        else
            cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}

/*
Test Case-> 

6 7 0
0 1 2
0 4 1
1 2 3 
4 2 2
4 5 4
2 3 6 
5 3 1
*/