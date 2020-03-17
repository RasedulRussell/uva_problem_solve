#include <bits/stdc++.h>

#define MOD 100000007
#define MAX 5000001

using namespace std;
using ll = long long;

vector<ll>prime;

void seive(){
    bitset<MAX>isPrime;
    isPrime.set();
    for( int i = 2; i*i < MAX; i++ ){
        if(isPrime[i]){
            for( int j = i*i; j < MAX; j+=i ){
                isPrime[j] = false;
            }
        }
    }
    for( int i = 2; i < MAX; i++ ){
        if(isPrime[i])prime.push_back(i);
    }
}

int main(){
    seive();
    int n, p;
    while(cin >> n && n ){
        ll res = 1;
        for(int i = 0; i < prime.size() && prime[i] <= n; i++){
            ll p = prime[i];
            ll tempN = n;
            ll tempP = p;
            ll t = 0;
            while( tempN/p ){
                ll a = tempN/p;
                t += a*(n%tempP+1) + ((a*(a-1))/2)*tempP;
                tempN /= p;
                tempP *= p;
                t = t%MOD;
            }
            t++;
            t = t%MOD;
            res = (res*t)%MOD;
        }
        cout << res << "\n";
    }
}

