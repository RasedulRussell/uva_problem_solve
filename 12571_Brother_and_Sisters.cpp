#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


int r[8] = {-1,  0, +1, +1, +1,  0, -1, -1};
int c[8] = {-1, -1, -1,  0, +1, +1, +1, 0};

///12571_Brother_and_Sisters.cpp



int32_t main(){
    __FastIO;
    int ans[230];
    int cs;
    cin >> cs;
    while(cs--){
        int n, q;
        cin >> n >> q;
        int input[n];
        for(int i = 0; i < n; i++){
            cin >> input[i];
        }
        for(int i = 0; i < 230; i++){
            int val = 0;
            for(int j = 0; j < n; j++){
                val = max(val, (i & input[j]));
            }
            ans[i] = val;
        }
        while(q--){
            int val; 
            cin >> val;
            cout << ans[val] << "\n";
        }
    }
    return 0;
}