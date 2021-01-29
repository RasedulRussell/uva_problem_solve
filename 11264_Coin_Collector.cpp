#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 7000
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11264_Coin_Collector.cpp

int32_t main(){
   __FastIO;
   int cs;
   cin >> cs;
   while(cs--){
      int n;
      cin >> n;
      int coin[n+1];
      for(int i = 0; i < n; i++){
         cin >> coin[i];
      }
      coin[n] = INF;
      int ans = (n>2)?2:1;
      for(int i = 0; i < n; i++){
         int sum = 0, cnt = 0;
         for(int j = i; j < n; j++){
            int tsum = sum+coin[j];
            if(j == n-1 && sum < coin[j]){
                cnt++;
                continue;
            }
            if(tsum < coin[j+1] && sum < coin[j]){
               sum =  tsum;
               cnt++;
            }
         }
         ans = max(ans, cnt);
      }
      cout << ans << '\n';
   }
}