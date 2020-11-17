#include<bits/stdc++.h>
using namespace std;

#define int int
#define INF 1000000
#define MAX 100005
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12844_Outwitting_the_Weighing_Machine.cpp

bool check(vector<int>& a, vector<int>& b){
   for(int i = 0; i < a.size(); i++){
      if(a[i] != b[i])return false;
   }
   return true;
}

int32_t main(){
   __FastIO;
   int cs = 1, tc;
   cin >> tc;
   while(tc--){
      vector<int>v(10);
      for(int i  = 0; i < 10; i++){
         cin >> v[i];
      }
      sort(v.begin(), v.end());
      vector<int>ans(5);
      for(int i = 1; i <= 400; i++){
         vector<int>temp(5);
         temp[0] = i;
         temp[1] = v[0] - temp[0];
         temp[2] = v[1] - temp[1];
         temp[4] = v[8] - temp[2];
         temp[3] = v[9] - temp[4];
         vector<int>tempV;
         for(int j = 0; j < 5; j++){
            ans[j] = temp[j];
            for(int k = j+1; k < 5; k++){
               tempV.push_back(temp[j]+temp[k]);
            }
         }
         sort(tempV.begin(), tempV.end());
         if(check(v, tempV)){
            break;
         }
      }
      sort(ans.begin(), ans.end());
      cout << "Case " << cs++ << ":";
      for(int i = 0; i < 5; i++){
         cout << " " << ans[i];
      }
      cout << "\n";
   }
   return 0;
}