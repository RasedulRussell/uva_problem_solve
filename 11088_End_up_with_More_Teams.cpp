#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11088_End_up_with_More_Teams.cpp

int n;
vector<int>points;
int dp[(1<<15) + 4][3][70];

int fun(int mask, int cnt, int sum){
    if(dp[mask][cnt][sum] != -1)return dp[mask][cnt][sum];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(mask & (1 << i))continue;
        int newcnt = cnt + 1;
        int newsum = sum + points[i];
        int newmask = mask;
        newmask |= (1<<i);
        int ok = 0;
        if(newcnt == 3){
            if(newsum >= 20){
                ok = 1;
            }
            newsum = 0;
            newcnt = 0;
        }
        ans = max(ans, ok + fun(newmask, newcnt, newsum));
    }
    return dp[mask][cnt][sum] = ans;
}

int32_t main(){
    __FastIO;
    int cs = 1;
    while(cin >> n && n){
        points.clear();
        memset(dp, -1, sizeof dp);
        int point;
        for(int i = 0; i < n; i++){
            cin >> point;
            points.push_back(point);
        }
        cout << "Case " << cs++ << ": " << fun(0, 0, 0) << "\n";
    }
    return 0;
}