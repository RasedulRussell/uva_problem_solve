#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define INF 10000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

long long MAX =  2147483647;
string inputNumber;
long long dp[202][202];

long long fun(int left, int right){
    if(right < left){
        return 0;
    }
    if(dp[left][right] != -1)return dp[left][right];
    long long ans = 0;
    long long temp = 0;
    bool flag = false;
    for(int i = left; i <= right; i++){
        temp = temp*10 + (inputNumber[i] - '0');
        if(temp > MAX){
            break;
        }
        ans = max(ans, temp+fun(i+1, right));
    }
    return dp[left][right] = ans;
}

int main(){
    __FastIO;
    int times;
    cin >> times;
    while(times--){
        cin >> inputNumber;
        memset(dp, -1, sizeof dp);
        cout << fun(0, inputNumber.size() - 1) << "\n";
    }
    return 0;
}