#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 100005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///558_Wormholes.cpp


class node{
public:
    int u, v, cost;
    node(int u, int v, int cost){
        this->cost = cost;
        this->u = u;
        this->v = v;
    }
};

int distances[MAX];
vector<node>adj;
int N, E;

string BellmanFord(){
    for(int i = 0; i < N; i++){
        distances[i] = INF;
    }
    distances[0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < adj.size(); j++){
            node edge = adj[j];
            distances[edge.v] = min(distances[edge.v], distances[edge.u] + edge.cost);
        }
    }
    for(int i = 0; i < adj.size(); i++){
        node edge = adj[i];
        if(distances[edge.v] > distances[edge.u] + edge.cost){
            return "possible";
        }
    }
    return "not possible";
}

int32_t main(){
    int cs;
    cin >> cs;
    while(cs--){
        adj.clear();
        cin >> N >> E;
        for(int i = 0; i < E; i++){
            int u, v, c;
            cin >> u >> v >> c;
            adj.push_back(node(u,v,c));
        }
        cout << BellmanFord() << "\n";
    }
    return 0;
}
