#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF 10000
#define MAX 45
#define MOD 10000000000007
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int32_t main(){
    __FastIO;
    int tc, cs = 1;
    cin >> tc;
    while(tc--){
        int l, m, n;
        cin >> l >> m >> n;
        int sz = l*l;
        int left = 0;
        int prev = 1;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(i == m){
                left = sum;
            }
            prev = (prev * sz) % MOD;
            sum = (sum + prev) % MOD;
            sz--;
        }
        int ans;
        if(sum < left){
            ans = (sum + MOD - left) % MOD;
        }else{
            ans = sum - left;
        }
        if(ans < 0){
            ans = ans + MOD;
        }
        cout << "Case " << cs++ << ": " << ans << "\n";
    }
    return 0;
}
