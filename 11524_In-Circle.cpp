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
#define     MAX 9999
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///11524_In-Circle.cpp

int32_t main(){
    cout << fixed << setprecision(4);
    int cs;
    cin >> cs;
    while(cs--){
        double r, m1, n1, m2, n2, m3, n3;
        cin >> r >> m1 >> n1 >> m2 >> n2 >> m3 >> n3;
        double k1 = (n1 + m1) / m1;
        double k2 = (n3 + m3) / n3;
        double k3 = (n1 / m1) * ((n2 + m2) / m2);
        double p = (k1 + k2 + k3) / 2.0;
        double hor = (k1 + k2 - k3) * (k2 + k3 - k1) * (k3 + k1 - k2);
        double x = 2.0 * r * sqrt((k1 + k2 + k3) / hor);
        double ans = (k1 + k2 + k3) / 2.0;
        ans = ans * r * x;
        cout << ans << "\n";
    }
    return 0;
}