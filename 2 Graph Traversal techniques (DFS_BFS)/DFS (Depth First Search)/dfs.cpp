#include <iostream>
#include <vector>

using namespace std;

class solution{
    void dfs(int node,vector<int>adj[] ,vector<int> &vis, vector<int>& ans){
        ans.push_back(node);
        vis[node] = 1;
        
        for (auto x : adj[node])
        {
            if(!vis[x]){
                dfs(x,adj,vis,ans);
            }
        }
    }

    public:

    vector<int>dfsOfGraph(int n,vector<int>adj[]){
        vector<int>vis(n+1,0) , ans;
        
        for (int i = 1; i < n+1; i++)
        {
            if(!vis[i]){
                dfs(i,adj,vis,ans);
            }
        }
        return ans;
    }

};

int main(){
    int t;
    cin>>t;

    while(t--){

        int n,m;
        cin>>n>>m;

        vector<int>adj[n+1];

        while(m--){
            int x,y;
            cin>>x>>y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        solution obj;

        vector<int>ans = obj.dfsOfGraph(n,adj);

        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }cout<<endl;
        
    }

    return 0;
}