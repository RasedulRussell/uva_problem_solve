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

int32_t main(){
    int n;
    while(cin >> n){
        
        vector<pii>one;
        vector<pii>three;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char ch; cin >> ch;
                if(ch == '1'){
                    one.push_back({i,j});
                }
                if(ch == '3'){
                    three.push_back({i,j});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < one.size(); i++){
            int mnDistance = INT_MAX;
            for(int j = 0; j < three.size(); j++){
                int ditances = abs(one[i].first-three[j].first) + abs(one[i].second-three[j].second);
                mnDistance = min(mnDistance, ditances);
            }
            ans = max(ans, mnDistance);
        }
        cout << ans << "\n";
    }
    return 0;
}