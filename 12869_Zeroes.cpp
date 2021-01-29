#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12869_Zeroes.cpp

int fzero(int n){
    int sum = 0;
    while(n >= 5){
        sum += (n/5);
        n /= 5;
    }
    return sum;
}

int32_t main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        n -= 5;
        int up = m / 5 + 1;
        int low = 0;
        if(n > 0){
            low = n / 5 + 1;
        }
        cout << (up - low ) << "\n";
    }
    return 0;
}

///0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18