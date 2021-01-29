#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10918_Tri_Tiling.cpp

int32_t main(){
    __FastIO;
    int ans[32];
    memset(ans, 0, sizeof ans);
    ans[0] = 1;
    ans[2] = 3;
    for(int i = 4; i <= 30; i+=2){
        ans[i] = 4*ans[i-2] - ans[i-4];
    }
    int n;
    while(cin >> n && n != -1){
        cout << ans[n] << "\n";
    }
    return 0;
}