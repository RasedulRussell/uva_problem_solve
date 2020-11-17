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
#define     MAX 200003
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, -1, 1};

int32_t main(){
    __FastIO;
    int dp[14][14][14];
    memset(dp, 0,sizeof dp);
    dp[1][1][1] = 1;
    for(int i = 2; i <= 13; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 1; k <= i; k++){
                dp[i][j][k] = dp[i-1][j][k] * (i - 2) + dp[i-1][j-1][k] + dp[i-1][j][k-1];
            }
        }
    }
    int cs;
    cin >> cs;
    while(cs--){
        int n, p, r;
        cin >> n >> p >> r;
        cout << dp[n][p][r] << "\n";
    }
    return 0;
}