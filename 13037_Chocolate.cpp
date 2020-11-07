#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"
#define nll cout << "\n"
#define ll long long
#define MAX 105
#define log_size 18
#define MOD 10007
#define INF 10000000000
#define ii pair<ll,ll>
#define presion cout << fixed << setprecision(6)

///13037_Chocolate.cpp

bool memo[3][100000];

int main(){
   __FastIO;
   int tc, cs = 1;
   cin >> tc;
   while(tc--){
      int sz[3];
      cin >> sz[0] >> sz[1] >> sz[2];
      memset(memo, false, sizeof memo);
      for(int i = 0; i < 3; i++){
         for(int j = 0; j < sz[i]; j++){
            int val; 
            cin >> val;
            memo[i][val] = true;
         }
      }
      cout << "Case #" << cs++ << ":\n";
      for(int i = 0; i < 3; i++){
         int unique = 0, nonunique = 0;
         for(int val = 0; val < 100000; val++){
            if(i == 0){
               if(memo[i][val] && !memo[1][val] && !memo[2][val])unique++;
               if(!memo[i][val] && memo[1][val] && memo[2][val])nonunique++;
            }else if( i == 1){
               if(memo[i][val] && !memo[0][val] && !memo[2][val])unique++;
               if(!memo[i][val] && memo[0][val] && memo[2][val])nonunique++;
            }else{
               if(memo[i][val] && !memo[0][val] && !memo[1][val])unique++;
               if(!memo[i][val] && memo[0][val] && memo[1][val])nonunique++;
            }
         }
         cout << unique << " " << nonunique << "\n";
      }
   }
   return 0;
}