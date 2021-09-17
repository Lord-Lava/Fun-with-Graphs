#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int u;
    int v;
    int wt;

    node(int first,int second,int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node n1, node n2){
    return n1.wt < n2.wt;
}

//DSU (Disjoint set Union) functions 

int findPar(int node,vector<int>&parent){
    if(node == parent[node]){
        return node;
    }

    return parent[node] = findPar(parent[node],parent);
}

void unionn(int u,int v,vector<int>&parent, vector<int>&rank){
    u = findPar(u,parent);
    v = findPar(v,parent);

    if(rank[u] < rank[v]){
        parent[v] = u;
    }
    else if(rank[v] < rank[u]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<node>edges;

    while(m--)
    {
        int u,v,wt;
        cin>>u>>v>>wt;

        edges.push_back(node(u,v,wt));
    }
    
    sort(edges.begin(),edges.end(),comp);

    vector<int>parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    vector<int>rank(n,0);

    int cost = 0;
    vector<pair<int,int>>mst;

    for(auto it: edges){
        if(findPar(it.u,parent) != findPar(it.v,parent)){
            mst.push_back({it.u,it.v});
            cost+=it.wt;
            unionn(it.u,it.v,parent,rank);
        }
    }

    cout<<cost<<endl;

    for(auto it: mst){
        cout<<it.first<<" - "<<it.second<<endl;
    }
    
    return 0;
}

//7 9
// 1 4 1
// 2 1 2
// 3 2 3
// 2 4 3
// 1 5 4
// 3 4 5
// 2 6 7
// 3 6 8
// 4 5 9