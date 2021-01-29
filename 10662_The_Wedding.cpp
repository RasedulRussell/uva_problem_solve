#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10662_The_Wedding.cpp

int32_t main(){
    __FastIO;
    string line;
    int t, r, h;
    while(cin >> t >> r >> h){
        int tr[22][22];
        int rh[22][22];
        int ht[22][22];
        for(int i = 1; i <= t; i++){
            for(int j = 0; j <= r; j++){
                cin >> tr[i][j];
            }
        }
        for(int i = 1; i <= r; i++){
            for(int j = 0; j <= h; j++){
                cin >> rh[i][j];
            }
        }
        for(int i = 1; i <= h; i++){
            for(int j = 0; j <= t; j++){
                cin >> ht[i][j];
            }
        }
        int mn = INT_MAX;
        int at,ar,ah;
        for(int tagency = 1; tagency <= t; tagency++){
            for(int res = 1; res <= r; res++){
                for(int hotel = 1; hotel <= h; hotel++){
                    if(tr[tagency][res] == 0 && rh[res][hotel] == 0 && ht[hotel][tagency] == 0){
                        int cost = tr[tagency][0] + rh[res][0] + ht[hotel][0];
                        if(cost < mn){
                            ///cout << tagency << " " <<  tr[tagency][0] << " " << rh[res][0] << " " << ht[hotel][0] << "\n";
                            mn = cost;
                            at = tagency;
                            ar = res;
                            ah = hotel;
                        }
                    }
                }
            }
        }
        if(mn == INT_MAX){
            cout << "Don't get married!\n";
        }else{
            cout << at-1 << " " << ar-1 << " " << ah-1 << ":" << mn << "\n";
        }
    }
    return 0;
}