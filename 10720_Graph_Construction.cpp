#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 7000
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10720_Graph_Construction.cpp



int32_t main(){
   __FastIO;
   int n;
   while(cin >> n && n){
      vector<int>degree;
      for(int i = 0; i < n; i++){
         int val;
         cin >> val;
         degree.push_back(val);
      }
      sort(degree.begin(), degree.end(), greater<int>());
      ///cout << degree[0] << "\n";
      int sum  = 0;
      bool flag = true;
      for(int i = 1; i <= n; i++){
         sum += degree[i-1];
         int k = i;
         int nextSum = k*(k-1);
         for(int j = k+1; j <= n; j++){
            nextSum += min(degree[j-1], k);
         }
         if(sum <= nextSum) continue;
         flag = false;
         break;
      }
      if(flag && (sum % 2 == 0)){
         cout << "Possible\n";
      }else{
         cout << "Not possible\n";
      }
   }
   return 0;
}