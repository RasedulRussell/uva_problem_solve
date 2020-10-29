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
#define     MAX 1000003
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     vl vector<ll>
#define     pb push_back
#define     con continue

int total, n;
vector<int>value;
int dp[102][2502];

int fun(int pos, int _total){
    if(_total >= total){
        return _total;
    }
    if(pos == n){
        return INT_MAX;
    }
    if(dp[pos][_total] != -1)return dp[pos][_total];

    int ans = fun(pos+1, _total);
    ans = min(ans, fun(pos+1, _total+value[pos]));
    return dp[pos][_total] = ans;
}

int32_t main(){
    __FastIO;
    int tc;
    cin >> tc;
    while(tc--){
        memset(dp, -1, sizeof dp);
        cin >> total >> n;
        value.resize(n);
        for(int i = 0; i < n; i++){
            cin >> value[i];
        }
        int ans = fun(0, 0);
        if(ans == INT_MAX){
            cout << "NO SOLUTION\n";
        }else{
            cout << ans << "\n";
        }
    }
    return 0;
}

