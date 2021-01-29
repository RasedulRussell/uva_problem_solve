#include<bits/stdc++.h>
using namespace std;

#define int int
#define INF 1000000
#define MAX 120
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///111_History_Grading.cpp

int32_t main(){
    int x[22];
    int y[22];
    int n, order;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &order);
        order--;
        x[order] = i;
    }
    while(1){
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(scanf("%d", &order) != 1){
                flag = true;
                break;
            }
            order--;
            y[order] = i;
        }
        if(flag)break;
        int dp[23][23];
        memset(dp, 0, sizeof dp);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        printf("%d\n", dp[n][n]);
    }
    return 0;
}