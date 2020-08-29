#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"
#define nll cout << "\n"
#define ll long long
#define MAX 500009
#define log_size 18
#define MOD 1000000007
#define INF 10000000000
#define ii pair<ll,ll>
#define presion cout << fixed << setprecision(6)



int main() {
    ll sum;
    while(cin >> sum && sum != -1){
        if(sum == 1){
            cout << sum << " = " << sum << " + ... + " << sum << "\n"; continue;
        }
        sum = 2LL * sum;
        ll ans = -1;
        for(int i = 1; i*i <= sum; i++){
            if(sum % i == 0){
                ll n = i;
                ll temp = sum - n*n + n;
                temp /= n;
                if(temp >= 0 && temp%2 == 0 && n != sum && n != sum/2){
                    ans = max(ans, n);
                }
                n = sum / i;
                temp = sum - n*n + n;
                temp /= n;
                if(temp >= 0 && temp%2 == 0 && n != sum && n != sum/2){
                    ans = max(ans, n);
                }
            }
        }
        ///cout << ans << "\n";
        ll x = sum - ((ans-1)*ans) ;
        x = x / (2*ans);
        if(x == 0){
            x = 1;
            ans--;
        }
        cout << sum/2 << " = " << x << " + ... + " << x+ans-1 << "\n";
    }
    return 0;
}