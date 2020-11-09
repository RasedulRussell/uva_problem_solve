#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1000005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11450_Wedding_Shopping.cpp

vector<int>market[23];
int dp[23][205];
int N, totalMoney;

int fun(int pos, int money){
    if(pos == N){
        if(money <= totalMoney){
            return money;
        }
        return 0;
    }
    if(money > totalMoney)return 0;
    if(dp[pos][money] != -1)return dp[pos][money];
    int ans = 0;
    for(int i = 0; i < market[pos].size(); i++){
        ans = max(ans, fun(pos+1, money+market[pos][i]));
    }
    return dp[pos][money] = ans;
}

void INI(){
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < 23; i++){
        market[i].clear();
    }
    return;
}

int32_t main(){
    __FastIO;
    int cs;
    cin >> cs;
    while(cs--){
        INI();
        cin >> totalMoney >> N;
        for(int i = 0; i < N; i++){
            int M; cin >> M;
            for(int j = 0; j < M; j++){
                int val; cin >> val;
                market[i].push_back(val);
            }
        }
        int ans = fun(0, 0);
        if(ans == 0){
            cout << "no solution\n";
        }else{
            cout << ans << "\n";
        }
    }
    return 0;
}