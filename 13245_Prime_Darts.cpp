#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 542
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///13245_Prime_Darts.cpp

vector<int>prime;
bool isPrime[MAX];
int dp[5005];

void seive(){
    memset(isPrime, true, sizeof isPrime);
    for(int i = 2; i*i < MAX; i++){
        if(isPrime[i]){
            for(int j = i*i; j < MAX; j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = 1; i < MAX; i++){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
}

int32_t main(){
    __FastIO;
    seive();
    int cs;
    cin >> cs;
    while(cs--){
        int n, q;
        cin >> n >> q;
        for(int i = 0; i <= q; i++){
            dp[i] = i;
        }
        for(int i = 1; i < n && prime[i] <= q; i++){
            for(int j = prime[i]; j <= q; j++){
                dp[j] = min(dp[j], dp[j - prime[i]]+1);
            }
        }
        cout << dp[q] << "\n";
    }
    return 0;
}