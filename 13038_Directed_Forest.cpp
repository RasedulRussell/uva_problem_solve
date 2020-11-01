#include<bits/stdc++.h>
using namespace std;

#define int int
#define MAX 100005
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int>adj[MAX];
bool visit[MAX];
vector<int>order;
int longestPath[MAX];
int N, E;

void dfs(int u){
    visit[u] = true;
    for(int v : adj[u]){
        if(!visit[v]){
            dfs(v);
        }
    }
    order.push_back(u);
    return;
}

void pathCalculation(int u){
    visit[u] = true;
    for(int v : adj[u]){
        if(visit[v]){
            longestPath[u] = max(longestPath[u], longestPath[v]+1);
            continue;
        }
        pathCalculation(v);
        longestPath[u] = max(longestPath[u], longestPath[v]+1);
    }
    return;
}

int LongestPath(){
    memset(visit, false, sizeof visit);
    order.clear();
    for(int i = 1; i <= N; i++){
        if(!visit[i]){
            dfs(i);
        }
    }
    for(int i = 1; i <= N; i++){
        longestPath[i] = 1;
        visit[i] = false;
    }
    for(int i = order.size() - 1; i >= 0; i--){
        int val = order[i];
        if(!visit[val]){
            pathCalculation(val);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, longestPath[i]);
    }
    return ans;
}

void INI(){
    for(int i = 0; i < MAX; i++){
        adj[i].clear();
    }
    return;
}

int32_t main(){
    __FastIO;
    int cs, tc = 1;
    cin >> cs;
    while(cs--){
        INI();
        cin >> N >> E;
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int ans = LongestPath();
        cout << "Case " << tc++ << ": " <<  ans << "\n";
    }
    return 0;
}