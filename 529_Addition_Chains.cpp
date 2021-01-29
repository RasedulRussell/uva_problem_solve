#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 7000
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///529_Addition_Chains.cpp

int n;
int ans[100];
bool check;

void dfs(int curr, int limit){
   if(curr == limit){
      if(ans[curr] == n){
         check = true;
      }
      return;
   }
   for(int i = 0; i <= curr; i++){
      for(int j = i; j <= curr; j++){
         int sum = ans[i] + ans[j];
         if(sum < ans[curr] || sum > n) continue;
         for(int k = curr+2; k <= limit; k++){
            sum = sum*2;
         }
         if(sum < n)continue;
         ans[curr+1] = ans[i] + ans[j];
         dfs(curr+1, limit);
         if(check)return;
      }
   }
}

int IDdfs(){
   check = false;
   for(int i = 0; i < 100; i++){
      ans[0] = 1;
      dfs(0, i);
      if(check){
         return i;
      }
   }
   return 1;
}

int32_t main(){
   __FastIO;
   while(cin >> n && n){
      int sz = IDdfs();
      for(int i = 0; i <= sz; i++){
         cout << ans[i];
         if(i != sz){
            cout << " ";
         }
      }
      cout << "\n";
   }
   return 0;
}