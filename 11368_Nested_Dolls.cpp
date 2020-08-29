#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

struct Node {
    int w, h;
    bool operator < (Node other)const{
        if(w == other.w){
            return h < other.h;
        }
        return w > other.w;
    }
};

int main(){
   __FastIO;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<Node>v(n);
        vector<int>dp(n+2);
        for(int i = 0; i < n; i++){
            cin >> v[i].w >> v[i].h;
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n+2; i++){
            dp[i] = 10000000;
        }
        dp[0] = -1;
        for(int i = 0; i < n; i++){
            int val = v[i].h;
            int idx = upper_bound(dp.begin(), dp.end(), val) - dp.begin();
            if(dp[idx] == 10000000){
                dp[idx] = val;
            }else{
                dp[idx] = min(dp[idx], val);
            }
        }
        int cnt = 0;
        for(int i = 1; i < n+2; i++){
            if(dp[i] != 10000000)cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}