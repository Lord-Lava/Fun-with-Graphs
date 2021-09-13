#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool checkCycle(int n,vector<int> adj[]){
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

    int ctr = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ctr++;
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    if(ctr == n) return false;
    return true;
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

    cout<<checkCycle(n,adj)<<endl;

    return 0;
}