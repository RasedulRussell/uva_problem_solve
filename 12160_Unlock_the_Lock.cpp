#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define INF 10000
#define MAX 1005
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
    int L, U, R, cs = 1;
    while(cin >> L >> U >> R){
        if(L == R && U == R && R == 0)break;
        vector<int>adj(R);
        for(int i = 0; i < R; i++){
            cin >> adj[i];
        }
        cout << "Case " << cs++ << ": ";
        
        queue<pair<int, int>>q;
        q.push(make_pair(L, 0));
        bool visit[10005];
        memset(visit, false, sizeof visit);
        visit[L] = true;
        bool check = true;

        while(!q.empty()){
            auto u = q.front();
            q.pop();
            ///cout << u.first << "\n";
            if(u.first == U){
                check = false;
                cout << u.second << "\n";
                break;
            }
            for(int i = 0; i < R; i++){
                int v = u.first + adj[i];
                v = v % 10000;
                if(visit[v]) continue;
                visit[v] = true;
                q.push(make_pair(v, u.second+1));
            }
        }
        if(check){
            cout << "Permanently Locked\n";
        }
    }
    return 0;
}

/*
0000 9999 1
1000
0000 9999 1
0001
5234 1212 3
1023 0101 0001
0 0 0
Case 1: Permanently Locked
Case 2: 9999
Case 3: 48
*/