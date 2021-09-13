#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}

vector<int> topological_sort(int n,vector<int>adj[]){
    stack<int>st;
    vector<int>vis(n,0);

    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
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

    vector<int>v = topological_sort(n,adj);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl;
    

    return 0;
}