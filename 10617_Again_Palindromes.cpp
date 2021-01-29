#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 2000005
#define MOD 1000000007
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"

///10617_Again_Palindromes.cpp

int dp[65][65];
string input;

int fun(int i, int j){
    if(i == j){
        return 1;
    }
    if(i > j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
    if(input[i] == input[j]){
        ans += fun(i+1, j)+fun(i, j-1)+1;
    }else{
        ans += fun(i, j-1) + fun(i+1, j) - fun(i+1, j-1);
    }
    return dp[i][j] = ans;
}

int32_t main(){
    int cs;
    cin >> cs;
    while(cs--){
       memset(dp, -1, sizeof dp);
       cin >> input;
       cout << fun(0, input.size()-1) << "\n";
    }
    return 0;
}