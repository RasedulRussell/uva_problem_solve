#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 120
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11069_A_Graph_Problem.cpp

int32_t main(){
    __FastIO;
    int dp[77];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    for(int i = 4; i <= 76; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    int n;
    while(cin >> n){
        cout << dp[n] << "\n";
    }
    return 0;
}