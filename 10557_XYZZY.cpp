#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 104
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

/// 10557_XYZZY.cpp

vector<int>adj[MAX];
vector<pii>doors;
bool visit[MAX];
int energy[MAX];
int minEnergy[MAX];
int N;

bool bfs(int sourse, int destination){
    memset(visit, false, sizeof visit);
    visit[sourse] = true;
    queue<int>q;
    q.push(sourse);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(visit[v]) continue;
            visit[v] = true;
            q.push(v);
        }
        if(visit[destination])return true;
    }
    return false;
}

bool BellmanFord(){
    if(N == 1)return true;
    if(N == 0)return false;
    if(!bfs(1, N))return false;
    for(int i = 0; i <= N; i++){
        minEnergy[i] = INF;
    }
    minEnergy[1] = -100;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < doors.size(); j++){
            pii u = doors[j];
            if(minEnergy[u.first]+energy[u.first] < min(0LL,minEnergy[u.second])){
                minEnergy[u.second] = minEnergy[u.first] + energy[u.first];
            }
        }
    }
    
    if(minEnergy[N]+energy[N] < 0){
        ///cout << "here\n";
        return true;
    }

    for(int i = 0; i < doors.size(); i++){
        pii u = doors[i];
        if((minEnergy[u.first] + energy[u.first] < min(0LL,minEnergy[u.second])) && bfs(1, u.first) && bfs(u.second, N))return true;
    }
    return false;
}

int32_t main(){
    __FastIO;
    while(cin >> N){
        if(N == -1)break;
        doors.clear();
        for(int i = 0; i < MAX; i++){
            adj[i].clear();
        }
        for(int i = 1; i <= N; i++){
            int en, E;
            cin >> en >> E;
            energy[i] = -en;
            if(i == 1){
                energy[i] = 0;
            }
            for(int j = 0; j < E; j++){
                int v; cin >> v;
                adj[i].push_back(v);
                doors.push_back({i, v});
            }
        }
        bool check = BellmanFord();
        if(check){
            cout << "winnable\n";
        }else{
            cout << "hopeless\n";
        }
    }
    return 0;
}