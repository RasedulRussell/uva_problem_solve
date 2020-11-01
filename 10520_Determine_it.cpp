#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, an1;

int fun(){
    int dp[n+1][n+1];
    memset(dp, 0, sizeof dp);
    dp[n][1] = an1;
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            if(i == n && j == 1)continue;
            if(i < j){
                int ans = 0;
                for(int k = i; k < j; k++){
                    ans = max(ans, dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] = ans;
            }else{
                int a = 0, b = 0;
                if(i < n){
                    for(int k = i+1; k <= n; k++){
                        a = max(a, dp[k][1] + dp[k][j]);
                    }
                }
                if(j > 0){
                    for(int k = 1; k < j; k++){
                        b = max(b, dp[i][k] + dp[n][k]);
                    }
                }
                dp[i][j] = (a + b);
            }
        }
    }
    return dp[1][n];
}

int32_t main(){
    while(cin >> n >> an1){
        cout << fun() << "\n";
    }
    return 0;
}