#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 10000
#define MAX 45
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int first, last;
int dp[MAX];

int utilFun(int prev){
    if(prev == last)return 1;
    if(prev > last)return 0;
    if(dp[prev] != -1)return dp[prev];
    int ans = 0;
    for(int next = prev+1; next <= last; next++){
        int diff = next - prev;
        if(next % diff == 0){
            ans += utilFun(next);
        }
    }
    return dp[prev] = ans;
}

int32_t main(){
    __FastIO;
    while(cin >> first >> last){
        if(first == last && first == 0)break;
        memset(dp, -1, sizeof dp);
        cout << first << " " << last << " " << utilFun(first) << "\n";
    }
    return 0;
}