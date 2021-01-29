#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 7000
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10570_Meeting_with_Aliens.cpp

int minSwap(vector<int>& arr){
   int n = arr.size();
   vector<int>edge[n];
   for(int i = 0; i < n; i++){
      int val = arr[i];
      edge[i].push_back(val);
   }
   vector<bool> visit(n, false);
   int ans = 0;
   for(int i = 0; i < n; i++){
      if(visit[i]) continue;
      int u = i;
      int cycleSize = 0;
      while(!visit[u]){
         visit[u] = true;
         u = edge[u][0];
         cycleSize++;
      }
      ans += (cycleSize-1);
   }
   return ans;
}

int32_t main(){
   int n;
   while(cin >> n && n){
      vector<int>input(n);
      for(int i = 0; i < n; i++){
         cin >> input[i];
         input[i]--;
      }
      int ans = INT_MAX;
      for(int i = 0; i < n; i++){
         int st = i;
         vector<int>temp;
         int k = i;
         for(int j = 0; j < n; j++){
            temp.push_back(input[k++]);
            k = k % n;
         }
         ans = min(ans, minSwap(temp));
      }
      reverse(input.begin(), input.end());
      for(int i = 0; i < n; i++){
         int st = i;
         vector<int>temp;
         int k = i;
         for(int j = 0; j < n; j++){
            temp.push_back(input[k++]);
            k = k % n;
         }
         ans = min(ans, minSwap(temp));
      }
      cout << ans << "\n";
   }
   return 0;
}