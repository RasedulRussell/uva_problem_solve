#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF 1000000
#define MAX 120
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11310_Delivery_Debacle.cpp

int32_t main(){
    __FastIO;
    int dp[41];
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    for(int i = 4; i <= 40; i++){
        dp[i] = dp[i-1] + 4*dp[i-2] + 2*dp[i-3];
    }
    int cs;
    cin >> cs;
    while(cs--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}