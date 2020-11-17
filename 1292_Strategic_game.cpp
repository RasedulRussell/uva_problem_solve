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
#define     MAX 1505
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///1292_Strategic_game.cpp

vector<int>adj[MAX];
int dp[MAX][2];

void INI(){
    for(int i = 0; i < MAX; i++){
        adj[i].clear();
    }
    return;
}

void fun(int u, int parent){

   for(int v : adj[u]){
       if(v == parent)continue;
       fun(v, u);
   }
   int placing_u = 1, nonPlacing = 0;
   for(int v : adj[u]){
       if(v == parent)continue;
       placing_u += dp[v][1];
       nonPlacing += dp[v][0];
   }
   dp[u][0] = placing_u;
   dp[u][1] = min(nonPlacing, placing_u);
   ///cout << u << "  " << dp[u][0] << " " << dp[u][1] << "\n";
}

void printGraph(int n){
    for(int i = 0; i < n; i++){
        cout << i << "|";
        for(int j : adj[i]){
            cout << " " << j ;
        }
        nll;
    }
}

int32_t main(){
    int n;
    while(cin >> n){
        INI();
        int root = 0;
        for(int i = 0; i < n; i++){
            int id, nunNode;
            char ch;
            cin >> id >> ch >> ch >> nunNode >> ch;
            for(int j = 0; j < nunNode; j++){
                int v; cin >> v;
                adj[id].push_back(v);
                adj[v].push_back(id);
            }
        }
        ///printGraph(n);
        for(int i = 0; i < n; i++){
            if(adj[i].size() > 1){
                fun(i, i);
                cout << min(dp[i][0], dp[i][1]) << "\n";
                break;
            }
        }
    }
    return 0;
}