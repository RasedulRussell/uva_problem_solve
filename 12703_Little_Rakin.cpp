#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define INF 10000
#define MAX 1005
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int smallPrimeFactor[MAX];

void seive(){
    for(int i = 0; i < MAX; i++){
        smallPrimeFactor[i] = i;
    }

    for(int i = 2; i < MAX; i++){
        if(smallPrimeFactor[i] == i){
            for(int j = i*2; j < MAX; j+=i){
                smallPrimeFactor[j] = min(smallPrimeFactor[j], i);
            }
        }
    }
    return;
}

int main(){
    seive();
    int cs;
    cin >> cs;
    while(cs--){
        int n, a, b;
        cin >> n >> a >> b;
        int dp[n+1][MAX];
        memset(dp, 0, sizeof dp);
        while(a > 1){
            int pf = smallPrimeFactor[a];
            dp[0][pf]++;
            a = a / pf;
        }
        while(b > 1){
            int pf = smallPrimeFactor[b];
            dp[1][pf]++;
            b = b / pf;
        }
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < MAX; j++){
                dp[i][j] = dp[i-1][j] + dp[i-2][j];
            }
        }
        for(int i = 0; i < MAX; i++){
            if(dp[n][i] > 0){
                cout << i << " " << dp[n][i] << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}