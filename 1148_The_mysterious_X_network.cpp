#include<bits/stdc++.h>
using namespace std;

#define int int
#define INF 10000
#define MAX 100005
#define MOD 10000000000007
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

/// 1148_The_mysterious_X_network.cpp

set<int>adj[MAX];
bool visit[MAX];

void INI(){
    for(int i = 0; i < MAX; i++){
        adj[i].clear();
        visit[i] = false;
    }
    return;
}

int bfs(int S, int D){
    queue<pii>q;
    visit[S] = true;
    q.push({S, 0});

    while(!q.empty()){
        pii u = q.front();
        q.pop();
        if(u.first == D)return u.second - 1;
        for(int v : adj[u.first]){
            if(visit[v]) continue;
            visit[v] = true;
            q.push({v, u.second+1});
        }
    }
    return 0;
}

int main(){
    __FastIO;
    int cs, flag = 0;
    cin >> cs;
    while(cs--){
        if(flag){
            cout << "\n";
        }
        flag = 1;
        INI();
        int N;
        cin >> N;
        for(int i = 0; i < N; i++){
            int u, nc; cin >> u >> nc;
            for(int j = 0; j < nc; j++){
                int v; cin >> v;
                adj[u].insert(v);
                adj[v].insert(u);
            }
        }
        int s,d;
        cin >> s >> d;
        cout << s << " " << d << " " << bfs(s,d) << "\n";
    }
    return 0;
}