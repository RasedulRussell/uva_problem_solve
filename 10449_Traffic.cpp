#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 209
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10449_Traffic.cpp


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
string ans[MAX];
vector<node>adj;
int N, E;

int distanceValue(int a, int b){
    int diff = b - a;
    return diff*diff*diff;
}

void BellmanFord(){
    for(int i = 1; i <= N; i++){
        distances[i] = INF;
        ans[i] = "";
    }
    distances[1] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < E; j++){
            node temp = adj[j];
            ///cout << distances[temp.v] << " " <<  distances[temp.u] + temp.cost << "\n";
            if(distances[temp.u] == INF)continue;
            distances[temp.v] = min(distances[temp.v], distances[temp.u] + temp.cost);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < E; j++){
            node temp = adj[j];
            ///cout << distances[temp.v] << " " <<  distances[temp.u] + temp.cost << "\n";
            if(distances[temp.u] == INF)continue;
            if(distances[temp.v] > distances[temp.u] + temp.cost){
                ans[temp.v] = "?";
            }
            distances[temp.v] = min(distances[temp.v], distances[temp.u] + temp.cost);
        }
    }
    for(int i = 1; i <= N; i++){
        if(ans[i] == "?") continue;
        int u = distances[i];
        if(u < 3 || u == INF){
            ans[i] = "?";
        }else{
            ans[i] = to_string(u);
        }
    }
    return;
}

int32_t main(){
    int cs = 1;
    while(cin >> N){
        int cost[N+1];
        for(int i = 1; i <= N; i++){
            cin >> cost[i];
        }
        adj.clear();
        cin >> E;
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj.push_back(node(u,v, distanceValue(cost[u], cost[v])));
            ///cout << u << " " << v << " " << distanceValue(cost[u], cost[v]) << "\n";
        }
        BellmanFord();
        cout << "Set #" << cs++ << "\n";
        int q;
        cin >> q;
        while(q--){
            int u;
            cin >> u;
            cout << ans[u] << "\n";
        }
    }
    return 0;
}
