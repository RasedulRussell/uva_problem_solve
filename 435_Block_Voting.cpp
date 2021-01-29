#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 7000
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///435_Block_Voting.cpp

int32_t main(){
   int cs = 1, tc;
   cin >> tc;
   while(tc--){
      int n;
      cin >> n;
      int vots[n];
      int total = 0;
      for(int i = 0; i < n; i++){
         cin >> vots[i];
         total += vots[i];
      }
      if(total & 1){
         total++;
      }
      int half = total / 2;
      int power[n];
      memset(power, 0, sizeof power);
      for(int i = 1; i < (1 << n); i++){
         int subsetSum = 0;
         for(int j = 0; j < n; j++){
            if((i & (1 << j))){
               subsetSum += vots[j];
            }
         }
         for(int j = 0; j < n; j++){
            if((i & (1 << j))){
               if((subsetSum >= half) && (subsetSum - vots[j]) < half){
                  power[j]++;
               }
            }
         }
      }
      for(int i = 0; i < n; i++){ ///party 1 has power index 10
         cout << "party " << i+1 << " has power index " << power[i] << "\n";
      }
      cout << "\n";
   }   
   return 0;
}