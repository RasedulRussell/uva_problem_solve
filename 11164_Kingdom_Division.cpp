#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11164_Kingdom_Division.cpp

int32_t main(){
    cout << fixed << setprecision(4);
    double a, b, c;
    int cs = 1;
    while(cin >> a >> b >> c){
        if(a == -1.0)break;
        cout << "Set " << cs++ << ":\n"; ///Set 1:
        if((b*b == a*c) || b == 0.0){
            cout << "Poor King!\n";
            continue;
        }
        if(a == 0.0 || b == 0.0 || c == 0.0){
            cout << "0.0000\n";
            continue;
        }
        double x = (a*b*c + a*a*c) / (b*b - a*c);
        double y = (b*x - a*c) / a;
        if((x+y) < 0.0){
            cout << "Poor King!\n";
            continue;
        }
        cout << (x + y) << "\n";
    }
    return 0;
}