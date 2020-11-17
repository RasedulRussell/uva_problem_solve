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
#define     MAX 9999
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///12101_Prime_Path.cpp

bool isPrime[MAX];
bool visit[MAX];
int steps[MAX];
vector<int>adj[MAX];

void seive(){
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i*i < MAX; i++){
        if(isPrime[i]){
            for(int j = i*i; j < MAX; j+=i){
                isPrime[j] = false;
            }
        }
    }
    isPrime[1] = false;
    return;
}

bool valid(int a, int b){
    string A = to_string(a);
    string B = to_string(b);
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        if(A[i] != B[i])cnt++;
    }
    return cnt <= 1;
}

int32_t main(){
    __FastIO;
    seive();
    vector<int>node;
    for(int i = 999; i < MAX; i++){
        if(isPrime[i] && i < 9999){
            node.push_back(i);
        }
    }
    for(int i = 0; i < node.size(); i++){
        for(int j = i+1; j < node.size(); j++){
            int u = node[i];
            int v = node[j];
            if(valid(u, v)){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
    int cs;
    cin >> cs;
    while(cs--){
        int sourse, destination;
        cin >> sourse >> destination;
        for(int i = 999; i <= 9999; i++){
            visit[i] = false;
            steps[i] = INF;
        }
        queue<int>q;
        q.push(sourse);
        visit[sourse] = true;
        steps[sourse] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(sourse == destination){
                break;
            }
            for(auto v : adj[u]){
                if(visit[v]) continue;
                steps[v] = steps[u] + 1;
                visit[v] = true;
                q.push(v);
            }
        }
        int val = steps[destination];
        if(val == INF){
            cout << "Impossible\n";
        }else{
            cout << val << "\n";
        }
    }
    return 0;
}
/*
Sample Input
3
1033 8179
1373 8017
1033 1033
Sample Output
6
7
0
*/
