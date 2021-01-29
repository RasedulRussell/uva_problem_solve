#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 105
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     EPS 1e-9

int lengthBoundary;
int values[55];
int n;
int mxlength, minlength;

int cnt = 0;
int taken[4];

int findLcm(){
    int lcm = taken[0];
    for(int i = 1; i < 4; i++){
        int gc = __gcd(lcm, taken[i]);
        lcm = (lcm * taken[i]) / gc;
    }
    return lcm;
}

void fun(int pos, int idx){
    if(idx  == 4){
        int lcm = findLcm();
        int ok = lengthBoundary / lcm;
        int minMax = ok*lcm;
        if(lengthBoundary % lcm > 0){
            ok++;
        }
        int maxMin = ok * lcm;
        mxlength = min(mxlength, maxMin);
        minlength = max(minMax, minlength);
        return;
    }
    if(pos >= n)return;
    taken[idx] = values[pos];
    fun(pos+1, idx+1);
    fun(pos+1, idx);
    return;
}

int32_t main(){
    ///__FastIO;
    int t;
    while(cin >> n >> t){
        if(n == 0 && t == 0)break;
        for(int i = 0; i < n; i++){
            cin >> values[i];
        }
        while(t--){
            cin >> lengthBoundary;
            minlength = LONG_MIN;
            mxlength = LONG_MAX;
            ///cout << "hello\n";
            fun(0, 0);
            cout << minlength << " " << mxlength << "\n";
        }
    }
    return 0;
}
