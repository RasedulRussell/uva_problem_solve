#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 22
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10364_Square.cpp

int input[MAX];
int N;
int dp[(1<<20)][4];
long long need;

int fun(int sum, int mask, int idx){
    if(sum == need){
        if(idx == 3){
            return 1;
        }
        return fun(0, mask, idx+1);
    }
    if(dp[mask][idx] != -1)return dp[mask][idx];
    int ans = 0;
    for(int i = 0; i < N; i++){
        if((mask & (1<<i))) continue;
        if(sum + input[i] > need) continue;
        ans = ans | fun(sum + input[i], mask | (1<<i), idx);
    }
    return dp[mask][idx] = ans;
}

int32_t main(){
    __FastIO;
    int cs; cin >> cs;
    while(cs--){
        memset(dp, -1, sizeof dp);
        cin >> N;
        need = 0;
        for(int i = 0; i < N; i++){
            cin >> input[i];
            need += input[i];
        }
        if(need % 4){
            cout << "no\n"; continue;
        }
        need = need / 4;
        cout << (fun(0, 0, 0) == 1 ? "yes" : "no") << "\n";
    }
    return 0;
}
