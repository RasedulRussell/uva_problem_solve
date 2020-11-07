#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11572_Unique_Snowflakes.cpp

int main(){
   int cs;
   cin >> cs;
   while(cs--){
      int n;
      cin >> n;
      long long arr[n];
      for(int i = 0; i < n; i++){
         cin >> arr[i];
      }
      int ans = 0;
      deque<long long>dq;
      map<long long, int>ok;
      for(int i = 0; i < n; i++){
         int val = arr[i];
         while(!dq.empty() && ok[val] >= 1){
            ok[dq.back()]--;
            dq.pop_back();
         }
         dq.push_front(val);
         ok[val]++;
         ans = max(ans, (int)dq.size());
      }
      cout << ans << "\n";
   }
   return 0;
}