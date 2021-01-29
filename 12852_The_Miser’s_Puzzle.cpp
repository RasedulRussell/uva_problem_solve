#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12852_The_Miser’s_Puzzle.cpp

int32_t main(){
    __FastIO;
    int tc;
    int n, lcm, val;
    cin >> tc;
    for(int cs = 1; cs  <= tc; cs++){
        cin >> n;
        cin >> lcm;
        for(int i = 1; i < n; i++){
            cin >> val;
            lcm = (lcm * val) / __gcd(lcm, val);
        }
        cout << "Case " << cs << ": " << lcm*35 << "\n";
    }
    return 0;
}