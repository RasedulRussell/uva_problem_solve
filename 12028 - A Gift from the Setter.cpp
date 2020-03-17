#include <bits/stdc++.h>

#define MOD 1000007
#define MAX 5000001


using namespace std;
using ll = long long;

void generateArray( int k, int c, int n, int a0, ll *arr ){
    arr[0] = a0;
    for(int i = 1; i < n; i++){
        arr[i] = (k*arr[i-1]+c)%MOD;
    }
}

int main(){
    int times;
    cin >> times;
    for(int Case = 1; Case <= times; Case++){
        int n, k, c, a0;
        cin >> k >> c >> n >> a0;
        ll arr[n+1];
        generateArray(k,c, n, a0, arr);
        ll qsum[n+1];
        sort( arr, arr+n );
        qsum[0] = arr[0];
        for(int i = 1; i < n; i++){
            qsum[i] = qsum[i-1]+arr[i];
        }
        ll res = 0;
        for(int i = 0; i < n; i++){
            int t = n-i-1;
            res += abs( t*arr[i] - (qsum[n-1] - qsum[i]) );
        }
        cout << "Case " << Case << ": " << res << "\n";
    }
}


