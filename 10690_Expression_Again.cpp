#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 105
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///10690_Expression_Again.cpp

int values[MAX];
int dp[55][5200];
int n, m;

int32_t main(){
    __FastIO;
    int x = 2510;
    while(cin >> n >> m){
        int sum = 0;
        for(int i = 0; i < (n+m); i++){
            cin >> values[i];
            sum += values[i];
        }
        
        memset(dp, 0, sizeof dp);
        int taken = min(n, m);
        dp[0][x] = 1;
        
        for(int val = 0; val < (n+m); val++){
            vector<pii>next;
            for(int k = 0; k <= val && k < taken; k++){
                for(int i = 0; i < 5200; i++){
                    if(dp[k][i]){
                        next.push_back({k+1, i+values[val]});
                    }
                }
            }
            for(int i = 0; i < next.size(); i++){
                if(next[i].second >= 5200 ) continue;
                dp[next[i].first][next[i].second] = 1;
            }
        }
        
        int mx = -INF, mn = INF;
        for(int i = 1; i < 5200; i++){
            if(dp[taken][i]){
                ///cout << a << "\n";
                mx = max(mx, (i - x)*(sum - i + x));
                mn = min(mn, (i - x)*(sum - i + x));
            }
        }
        cout << mx << " " << mn << "\n";
    }
    return 0;
}