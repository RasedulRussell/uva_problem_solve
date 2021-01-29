#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12918_Lucky_Thief.cpp

int32_t main(){
    __FastIO;
    int cs;
    cin >> cs;
    while(cs--){
        int n, m;
        cin >> n >> m;
        int ans = n*(m-n);
        ans += ((n*(n-1)) / 2);
        cout << ans << "\n";
    }
    return 0;
}