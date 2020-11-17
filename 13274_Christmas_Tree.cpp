#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 1005
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///13274_Christmas_Tree.cpp

vector<int>adj[MAX];
int dp[MAX];
int N, K;

void INI(){
    for(int i = 0; i < MAX; i++){
        adj[i].clear();
        dp[i] = 1;
    }
    return;
}

void dfs(int u, int parent){
    priority_queue<int>pq;
    for(int v : adj[u]){
        if(v == parent) continue;
        dfs(v, u);
        pq.push(dp[v]);
    }
    if(pq.size() < K){
        dp[u] = 1;
    }else{
        for(int i = 0; i < K; i++){
            dp[u] += pq.top();
            pq.pop();
        }
    }
    return;
}

int32_t main(){
    __FastIO;
    int tc, cs = 1;
    cin >> tc;
    while(tc--){
        INI();
        cin >> N >> K;
        for(int i = 1; i < N; i++){
            int u, v; 
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 1);
        cout << "Case " << cs++ << ": " << dp[1] << "\n";
    }
    return 0;
}