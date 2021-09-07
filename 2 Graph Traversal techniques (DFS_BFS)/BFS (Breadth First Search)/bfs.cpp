#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class solution{
    public:
        vector<int>bfs(int n,vector<int> adj[]){
            vector<int> bfs;
            vector<int> vis(n+1,0);

            for(int i=1;i<n+1;i++){
                if(!vis[i]){
                    queue<int>q;
                    q.push(i);
                    vis[i] = 1;

                    while(!q.empty()){
                        int node = q.front();
                        q.pop();
                        bfs.push_back(node);

                        for(auto it: adj[node]){
                            if(!vis[it]){
                                q.push(it);
                                vis[it] = 1;
                            }
                        }
                    }
                }
            }
            return bfs;
        }
};

int main(){
    int t;  //for multiple graphs
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<int> adj[n+1];

        while(m--){
            int u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solution obj;

        vector<int>ans = obj.bfs(n,adj);

        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }cout<<"\n";
    }
    
    return 0;
}