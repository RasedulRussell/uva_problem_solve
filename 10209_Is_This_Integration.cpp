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
#define     MAX 1505
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue
#define     PI cos(-1)

///10209_Is_This_Integration.cpp

int32_t main(){
    cout << fixed << setprecision(3);
    double r;
    while(cin >> r){
        r = r*r;
        double sqrtThree = sqrt(3.0);
        double a = 1 - (M_PI / 6.0) - (sqrtThree / 4.0);
        a = a * r;
        double b = (M_PI / 12.0) - 1 + (sqrtThree / 2.0);
        b = b * r;
        double c = (M_PI / 3.0) + 1 - sqrtThree;
        c = c * r;
        cout << c << " " << 4.0 * b << " " << 4.0 * a << "\n";
    }
    return 0;
}