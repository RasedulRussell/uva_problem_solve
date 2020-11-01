#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"
#define nll cout << "\n"
#define ll long long
#define MAX 62
#define log_size 18
#define MOD 10007
#define INF 10000000000
#define ii pair<ll,ll>
#define presion cout << fixed << setprecision(6)


int dp[MAX][MAX][MAX];
int dp1[MAX][MAX][MAX];
int dp2[MAX][MAX][MAX];
string first, second, third;

int utilFun(){
   int sizeofThird = third.size() + 1;
   int sizeofFirst = first.size() + 1;
   int sizeofSecond = second.size() + 1;

   memset(dp, 0, sizeof dp);
   memset(dp1, 0, sizeof dp1);
   memset(dp2, 0, sizeof dp2);

   for(int i = 0; i < sizeofFirst; i++){
      for(int j = 0; j < sizeofSecond; j++){
         dp[0][i][j] = 1;
         dp1[0][i][j] = 1; 
         dp2[0][i][j] = 1;
      }
   }

   for(int k = 1; k < sizeofThird; k++){
      for(int i = 0; i < sizeofFirst; i++){
         for(int j = 0; j < sizeofSecond; j++){
            if(i){
               dp1[k][i][j] = dp1[k][i-1][j];
               if(first[i-1] == third[k-1]){
                  dp1[k][i][j] += dp[k-1][i-1][j];
                  dp1[k][i][j] = dp1[k][i][j] % MOD;
               }
            }
            if(j){
               dp2[k][i][j] = dp2[k][i][j-1];
               if(second[j-1] == third[k-1]){
                  dp2[k][i][j] += dp[k-1][i][j-1];
                  dp2[k][i][j] = dp2[k][i][j] % MOD;
               }
            }
            dp[k][i][j] = (dp1[k][i][j] + dp2[k][i][j]) % MOD;
         }
      }
   }

   return dp[sizeofThird-1][sizeofFirst-1][sizeofSecond-1];
}

int main(){
   __FastIO;
   int cs;
   cin >> cs;
   while(cs--){
      cin >> first >> second >> third;
      cout << utilFun() << "\n";
   }
   return 0;
}