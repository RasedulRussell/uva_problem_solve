#include<bits/stdc++.h>
using namespace std;
#define INF 10000
#define MAX 10001
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
    __FastIO;
   int test;
   cin >> test;
   while(test--){
       int payble, N;
       cin >> payble >> N;
       int memo[10002], coin[N+1];
       for(int i = 0; i < N; i++){
           cin >> coin[i];
       }

       for(int i = 1; i <= 10000; i++){
           memo[i] = INF;
       }
       memo[0] = 0;

       for(int i = 0; i < N; i++){
           for(int j = 10000; j > 0; j--){
               if(j - coin[i] >= 0 && memo[j-coin[i]] + 1 < memo[j]){
                   memo[j] = memo[j-coin[i]] + 1;
               }
           }
       }

       for(int i = payble; i <= 10000; i++){
           if(memo[i] != INF){
               cout << i << " " << memo[i] << "\n";
               break;
           }
       }
   }
   return 0;
}