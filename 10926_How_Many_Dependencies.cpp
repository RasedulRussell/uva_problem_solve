#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define INF 10000
#define MAX 105
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int>adj[MAX];
bool visit[MAX];

void dfs(int u){
    visit[u] = true;
    for(int v : adj[u]){
        if(visit[v]) continue;
        dfs(v);
    }
    return;
}

int main(){
    __FastIO;
    int N;
    while(cin >> N && N){
        for(int i = 1; i <= N; i++){
            adj[i].clear();
            int E; cin >> E;
            for(int j = 0; j < E; j++){
                int v; cin >> v;
                adj[i].push_back(v);
            }
        }
        int ans = 0, mx = 0;
        for(int i = 1; i <= N; i++){
            memset(visit, false, sizeof visit);
            dfs(i);
            int cnt = 0;
            for(int j = 1; j <= N; j++){
                if(visit[j]) cnt++;
            }
            if(cnt > mx){
                mx = cnt;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}