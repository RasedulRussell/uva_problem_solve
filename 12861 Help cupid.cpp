#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12861 Help cupid.cpp
int dp[1002][1002];

int calculaton(int a, int b){
    a = abs(a - b);
    return min(a, (24 - a));
}

int fun(int i, int j, vector<int>& arr){
    if(i >= j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans1 = calculaton(arr[i], arr[i+1]) + fun(i+2, j, arr);
    int ans2 = calculaton(arr[i], arr[j]) + fun(i+1, j-1, arr);
    int ans3 = calculaton(arr[j], arr[j-1]) + fun(i, j-2, arr);
    return dp[i][j] = min(ans1, min(ans2, ans3));
}

int32_t main(){
    __FastIO;
    int n;
    while(cin >> n){
        memset(dp, -1, sizeof dp);
        vector<int>times(n);
        for(int i = 0; i < n; i++){
            cin >> times[i];
        }
        sort(times.begin(), times.end());
        cout << fun(0, n-1, times) << "\n";
    }
    return 0;
}