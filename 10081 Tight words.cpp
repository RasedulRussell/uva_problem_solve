#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fractional cout << fixed << setprecision(5)
///10081 Tight words.cpp

int n, k;
double dp[102][10];

double fun(){
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= k; i++){
        dp[1][i] = 1.0;
    }
    for(int len = 2; len <= n; len++){
        for(int digit = 0; digit <= k; digit++){
            if(digit == 0){
                dp[len][digit] = dp[len-1][digit] + dp[len-1][digit+1];
            }else if(digit == k){
                dp[len][digit] = dp[len-1][digit] + dp[len-1][digit-1];
            }else{
                dp[len][digit] = dp[len-1][digit] + dp[len-1][digit+1] + dp[len-1][digit-1];
            }
        }
    }
    return 100.0 * accumulate(dp[n], dp[n]+k+1, 0.0) / pow((double)k+1, n);
}

int32_t main(){
    __FastIO;
    fractional;
    while(cin >> k >> n){
        cout << fun() << "\n";
    }
    return 0;
}