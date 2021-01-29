#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///665_False_coin.cpp

int32_t main(){
    __FastIO;
    int tc;
    cin >> tc;
    for(int cs = 1; cs <= tc; cs++){
        if(cs != 1){
            cout << "\n";
        }
        int n, m;
        cin >> n >> m;
        bool visit[n+1];
        memset(visit, true, sizeof visit);
        for(int i = 0; i < m; i++){
            int s;
            cin >> s;
            int arr[2*s];
            for(int j = 0; j < 2*s; j++){
                cin >> arr[j];
            }
            string op;
            cin >> op;
            if(op == "="){
                for(int j = 0; j < 2*s; j++){
                    visit[arr[j]] = false;
                }
            }
        }
        int cnt = 0;
        int val = 0;
        for(int i = 1; i <= n; i++){
            if(visit[i]){
                cnt++;
                val = i;
            }
        }
        if(cnt > 1){
            val = 0;
        }
        cout << val << "\n";
    }
    return 0;
}