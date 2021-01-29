#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 100003
#define MOD  10000019
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11977_Story_of_Tomisu_Ghost.cpp

bool prime[MAX];
vector<int>primes;

void seive(){
    memset(prime, true, sizeof prime);
    for(int i = 2; i < MAX; i++){
        if(prime[i]){
            primes.push_back(i);
            for(int j = i * 2; j < MAX; j += i){
                prime[j] = false;
            }
        }
    }
    return;
}

int bigMode(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int32_t main(){
    __FastIO;
    seive();
    int tc, cs = 1;
    cin >> tc;
    while(tc--){
        int n, t;
        cin >> n >> t;
        vector<pii>factorial;
        for(int i = 0; i < primes.size() && prime[i] <= n; i++){
            int pf = primes[i];
            int sum = 0;
            int N = n;
            while(N){
                sum += (N / pf);
                N /= pf;
            }
            factorial.push_back({pf, (sum / t)});
        }
        int ans = 1;
        for(int i = 0; i < factorial.size(); i++){
            if(factorial[i].second == 0) continue;
            ans = ans * bigMode(factorial[i].first, factorial[i].second);
            ans = ans % MOD;
        }
        cout << "Case " << cs++ << ": " << ((ans == 1)?-1:ans) << "\n";
    }
    return 0;
}