#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 100005 ///100000
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10003_Cutting_Sticks.cpp

int n;
int dp[55][55];
vector<int>position;

int fun(int l, int r){
   if(l+1 == r){
      return 0;
   }
   if(dp[l][r] != -1)return dp[l][r];
   int ans = INT_MAX;
   for(int i = l+1; i < r; i++){
      ans = min(ans, fun(l, i)+fun(i, r)+(position[r]-position[l]));
   }
   return dp[l][r] = ans;
}

int32_t main(){
   __FastIO;
    int l;
    while(cin >> l && l){
       memset(dp, -1, sizeof dp);
       position.clear();
       position.push_back(0);
       cin >> n;
       for(int i = 0;i < n; i++){
          int pos;
          cin >> pos;
          position.push_back(pos);
       }
       position.push_back(l);
       cout << "The minimum cutting is " << fun(0, n+1) << ".\n";
    }
   return 0;
}