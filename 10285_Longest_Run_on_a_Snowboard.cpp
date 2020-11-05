#include<bits/stdc++.h>
using namespace std;

#define int int
#define INF 10000
#define MAX 10005
#define MOD 10000000000007
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int>adj[MAX];
vector<int>order;
int longestPath[MAX];
int visit[MAX];
pair<int, int>grid[105][105];
int N, M;

void INI(){
    for(int i = 0; i < MAX; i++){
        longestPath[i] = 1;
        visit[i] = false;
        adj[i].clear();
    }
    order.clear();
    return;
}

void dfs(int u){
    visit[u] = true;
    for(int v : adj[u]){
        if(visit[v]) continue;
        dfs(v);
    }
    order.push_back(u);
    return;
}

void LongestPath(int u){
    visit[u] = true;
    for(int v : adj[u]){
        if(visit[v]){
            longestPath[u] = max(longestPath[u], longestPath[v]+1); 
            continue;
        }
        LongestPath(v);
        longestPath[u] = max(longestPath[u], longestPath[v]+1);
    }
    return;
}

int SOLUTION(){
    INI();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int id = grid[i][j].first;
            int value = grid[i][j].second;
            if(i-1 >= 0 && grid[i-1][j].second < value){
                adj[id].push_back(grid[i-1][j].first);
            }
            if(i+1 < N && grid[i+1][j].second < value){
                adj[id].push_back(grid[i+1][j].first);
            }
            if(j-1 >= 0 && grid[i][j-1].second < value){
                adj[id].push_back(grid[i][j-1].first);
            }
            if(j+1 < M && grid[i][j+1].second < value){
                adj[id].push_back(grid[i][j+1].first);
            }
        }
    }
    for(int i = 1; i <= N*M; i++){
        if(visit[i]) continue;
        dfs(i);
    }
    memset(visit, false, sizeof visit);
    int mx = 0;
    for(int i = 1; i <= N*M; i++){
        if(visit[i]) continue;
        LongestPath(i);
        mx = max(longestPath[i], mx);
    }
    return mx;
}

int32_t main(){
    __FastIO;
    int cs;
    cin >> cs;
    while(cs--){
        string str;
        cin >> str >> N >> M;
        int id = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                grid[i][j].first = id++;
                cin >> grid[i][j].second;
            }
        }
        cout << str << ": " << SOLUTION() << "\n";
    }
    return 0;
}

/*
2
Feldberg 10 5
56 14 51 58 88
26 94 24 39 41
24 16 8 51 51
76 72 77 43 10
38 50 59 84 81
5 23 37 71 77
96 10 93 53 82
94 15 96 69 9
74 0 62 38 96
37 54 55 82 38
Spiral 5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/