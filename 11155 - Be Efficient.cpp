#include <bits/stdc++.h>

#define MOD 100000007
#define MAX 5000001

using namespace std;
using ll = long long;


void solution(int a, int b, int c, int m, int n, ll *arr){
    arr[0] = a;
    for( int i = 1; i < n; i++ ){
        arr[i] = (arr[i-1]*b+c)%m + 1;
    }
}

int main(){
    int a, b, c, m, n, t;
    cin >> t;
    for(int Case = 1; Case <= t; Case++){
        cin >> a >> b >> c >> m >> n;
        ll arr[n];
        solution(a,b,c,m,n, arr);
        int fre[m];
        memset( fre, 0, sizeof fre );
        int sum = 0;
        for(int i = 0; i < n; i++){
            ////cout << arr[i] << " ";
            sum += arr[i];
            sum = sum%m;
            fre[sum]++;
        }
        ll ans = (fre[0]*(fre[0]+1))/2;
        for( int i = 1; i < m; i++ ){
            ans = ans+(fre[i]*(fre[i]-1))/2;
        }
        cout << "Case " << Case << ": " << ans << "\n";
    }
}

