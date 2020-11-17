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
#define     MAX 100005
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///13214_The_Robots_Grid.cpp

int32_t main(){
    int dp[30][30];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < 30; i++){
        dp[0][i] = 1;
    }
    for(int j = 0; j < 30; j++){
        dp[j][0] = 1;
    }
    for(int colam = 1; colam < 30; colam++){
        for(int row = 1; row < 30; row++){
            dp[row][colam] = dp[row][colam-1] + dp[row-1][colam];
        }
    }
    int cs;
    cin >> cs;
    while(cs--){
        int N, M;
        cin >> N >> M;
        cout << dp[N-1][M-1] << "\n";
    }
    return 0;
}