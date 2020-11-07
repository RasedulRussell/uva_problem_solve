#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 13
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///1240_ICPC_Team_Strategy.cpp

int input[4][MAX];
int N;
int dp[4100][4][285];

int fun(int mask, int prev, int sum){
    if(sum == 280 || __builtin_popcount(mask) == N){
        return __builtin_popcount(mask);
    }
    if(sum > 280)return 0;
    if(dp[mask][prev][sum] != -1)return dp[mask][prev][sum];
    int ans = 0;
    for(int i = 0; i < N; i++){
        if((mask & (1 << i)))continue;
        for(int j = 1; j <= 3; j++){
            if(prev == j)continue;
            if(sum + input[j][i] <= 280){
                ans = max(ans, fun((mask | (1<<i)), j, sum + input[j][i]));
            }else{
                ans = max(ans, (int)__builtin_popcount(mask));
            }
        }
    }
    return  dp[mask][prev][sum] = ans;
}
int32_t main(){
    __FastIO;
    int cs;
    cin >> cs;
    while(cs--){
        cin >> N;
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= 3; i++){
            for(int j = 0; j < N; j++){
                cin >> input[i][j];
            }
        }
        cout << fun(0, 0, 0) << "\n";
    }
    return 0;
}

/*
2
3
100 100 80
190 120 90
120 150 100
4
50 20 300 300
200 100 30 250
140 120 100 100
2
4
*/