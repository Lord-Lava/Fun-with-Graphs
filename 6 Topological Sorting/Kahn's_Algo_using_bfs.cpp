#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topological_sort(int n,vector<int>adj[]){
    queue<int>q; vector<int>indegree(n,0);

    for (int i = 0; i < n; i++)
    {
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int>topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
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