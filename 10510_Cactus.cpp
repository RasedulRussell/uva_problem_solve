#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10510_Cactus.cpp

vector<int>adj[MAX];
int color[MAX];


void INI(){
    for(int i = 0; i < MAX; i++){
        adj[i].clear();
        color[i] = 0;
    }
    return;
}

int edge = 0;

bool dfs(int u){
    color[u] = 1;
    for(int v : adj[u]){
        if(color[v] == 0){
            if(dfs(v))return true;
        }else if(color[v] == 2){
            return true;
        }
    }
    color[u] = 2;
    return false;
}


int32_t main(){
    __FastIO;
    int n, m;
    int cs;
    cin >> cs;
    while(cs--){
        cin >> n >> m;
        INI();
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        bool cac = true;
        int scc = 0;
        for(int i = 0; i < n; i++){
            if(color[i] == 0){
                scc++;
                if(dfs(i)){
                    cac = false;
                    break;
                }
            }
        }
        if(cac && scc == 1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}