#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 7000
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12205_Happy_Telephones.cpp

int overlap(int a, int b, int c, int d){
   if((a <= c && b >= c) || (a <= d && b >= d) || (c <= a && d >= a) || (c <= b && d >= b))return 1;
   return 0;
}

int32_t main(){
   int n, m;
   while(cin >> n >> m){
      if(n == 0 && m == 0)break;
      vector<pair<int, int>>interval;
      for(int i = 0; i < n; i++){
         int a, b, s, d;
         cin >> a >> b >> s >> d;
         interval.push_back({s, s+d-1});
      }
      while(m--){
         int s, d;
         cin >> s >> d;
         d = s + d-1;
         int cnt = 0;
         for(int i = 0; i < n; i++){
            cnt += overlap(interval[i].first, interval[i].second, s, d );
         }
         cout << cnt << "\n";
      }
   }
   return 0;
}