#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX 1000005

using namespace std;
using ll = long long;

int smallPrimeFactor[MAX];
vector<unordered_map<int,ll>>primeFactor(MAX);

void factorize(){
    for( int i = 2; i < MAX; i++ ){
        smallPrimeFactor[i] = i;
    }
    for(int i = 2; i < MAX; i++){
        if( smallPrimeFactor[i] == i ){
            for(ll j = i*2; j < MAX; j+=i){
                smallPrimeFactor[j] = min( smallPrimeFactor[j], i );
            }
        }
    }
}


void calculatingPrimeFrequency( ){
    factorize();
    for(int i = 2; i < MAX; i++){
        int n = i;
        while( smallPrimeFactor[n] != n ){
            primeFactor[i][smallPrimeFactor[n]]++;
            n /= smallPrimeFactor[n];
        }
        if( n > 1 ){
            primeFactor[i][n]++;
        }
    }
}

ll min( ll a, ll b ){
    return (a<b)?a:b;
}

ll fun( ll n, int p ){
    ll res = 0, cnt = 1, multiple = p;
    while( n >= multiple ){
        for( int i = 1; n-multiple*i+1 > 0; i++ ){
            if(i%p == 0)continue;
            ll times = n - multiple*i + 1;
            times = (times*(times+1))/2;
            times = times*cnt;
            res += times;
        }
        multiple = multiple*p;
        cnt++;
    }
    return res;
}

int main(){
    calculatingPrimeFrequency();
    ///cout << "ok\n";
    int n, base;
    while(cin >> n >> base){
        if( n == 0 && base == 0 )return 0;
        ll res = LONG_LONG_MAX;
        for( auto x : primeFactor[base] ){
            res = min( res, fun( n, x.first )/x.second );
        }
        cout << res << "\n";
    }
}

