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

///11414_Dream.cpp

int32_t main(){
    __FastIO;
    int cs;
    cin >> cs;
    while(cs--){
        int n;
        cin >> n;
        vector<int>edge(n);
        for(int i = 0; i < n; i++){
            cin >> edge[i];
        }
        sort(edge.begin(), edge.end(), greater<int>());
        int sum = 0;
        bool check = true;
        for(int i = 1; i <= n; i++){
            sum += edge[i-1];
            int k = i;
            int tempSum = (k * (k-1));
            for(int j = k+1; j <= n; j++){
                tempSum += min(edge[j-1], k);
            }
            if(sum <= tempSum) continue;
            check = false;
            break;
        }
        if(check && sum%2 == 0){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}