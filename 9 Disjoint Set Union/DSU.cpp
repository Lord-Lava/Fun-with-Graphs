#include <iostream>

using namespace std;

int parent[100001];
int rank_set[100001];

void make_set(int n){
    for (int i = 1; i <= n; i++)
    {
        rank_set[i] = 0;
        parent[i] = i;
    }
}

int find_par(int node){         //Time Complexity-> O(4*α(n)) , where α(n) = inverse Ackermann function. (with path compression)
    if(node == parent[node]){
        return node;
    }

    return parent[node] = find_par(parent[node]);   //path compression    7 -> 6 -> 4 -> 3
}

void make_union(int u, int v){
    u = find_par(u);
    v = find_par(v);

    if(rank_set[u] < rank_set[v]){
        parent[u] = v;
    }
    else if(rank_set[u] > rank_set[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank_set[u]++;
    }
}

int main(){
    int n;
    cin>>n;

    make_set(n);

    int m;
    cin>>m;

    while(m--){
        int u,v;
        cin>>u>>v;

        make_union(u,v);
    }

    //whether 2 and 3 belong to the same component or not ?

    if(find_par(2) != find_par(3)){
        cout<<"Different Component\n";
    }
    else{
        cout<<"Same component\n";
    }

    return 0;
}