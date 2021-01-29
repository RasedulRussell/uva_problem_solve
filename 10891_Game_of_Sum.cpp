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
#define     MAX 105
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///10891_Game_of_Sum.cpp

int N;
int dp[MAX][MAX];
int sum[MAX];

int segSum(int i, int j){
    return (sum[j] - sum[i-1]);
}

int fun(int l, int r){
    if(r < l){
        return 0;
    }
    if(l == r){
        return segSum(l, r);
    }
    if(dp[l][r] != -INF){
        return dp[l][r];
    }
    int ans = LONG_MIN;
    for(int i = l; i <= r; i++){
        ans = max(ans, segSum(l, i) - fun(i+1, r));
        ans = max(ans, segSum(i, r) - fun(l, i-1));
    }
    return dp[l][r] = ans;
}

int32_t main(){
    while(cin >> N && N){
       sum[0] = 0;
       for(int i = 1; i <= N; i++){
           cin >> sum[i];
           sum[i] += sum[i-1];
       }
       for(int i = 0; i <= N; i++){
           for(int j = 0; j <= N; j++){
               dp[i][j] = -INF;
           }
       }
       cout << fun(1, N) << "\n";
    }
    return 0;
}