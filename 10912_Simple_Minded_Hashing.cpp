#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 70
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define  dbg cout << "dbg\n"

///10912_Simple_Minded_Hashing.cpp

int dp[30][30][360];
int goal;
int need;

int fun(int pos, int cnt, int sum){
   if(cnt == need){
      if(sum == goal)return 1;
      return 0;
   }
   if(pos > 26 || sum > goal)return 0;
   if(dp[pos][cnt][sum] != -1)return dp[pos][cnt][sum];
   int ans = fun(pos+1, cnt, sum);
   ans += fun(pos+1, cnt+1, sum+pos);
   return dp[pos][cnt][sum] = ans;
}

int32_t main(){
   __FastIO;
   int cs = 1;
   while(cin >> need >> goal){
      if(need == 0 && goal == 0) break;
      if(need > 26 || goal > 352){
         cout << "Case " << cs++ << " 0\n"; continue;
      }
      memset(dp, -1, sizeof dp);
      cout << "Case " << cs++ << ": " << fun(1, 0, 0) << "\n";
   }
   return 0;
}