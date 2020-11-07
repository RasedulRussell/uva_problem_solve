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

///895_Word_Problem.cpp

int main(){
   __FastIO;
   int memo[1002][26];
   memset(memo, 0, sizeof memo);
   string word;
   int N = 0;
   while(cin >> word && word != "#"){
      for(char ch : word){
         memo[N][ch - 'a']++;
      }
      N++;
   }
   string puzzel;
   cin.ignore();
   while(getline(cin, puzzel) && puzzel != "#"){
      int fre[26];
      memset(fre, 0, sizeof fre);
      for(int i = 0 ; i < puzzel.size(); i++){
         if(puzzel[i] >= 'a' && puzzel[i] <= 'z'){
            fre[puzzel[i] - 'a']++;
         }
      }
      int cnt = 0;
      for(int i = 0; i < N; i++){
         bool flag = true;
         for(int j = 0; j < 26; j++){
            if(memo[i][j] > fre[j]){
               flag = false;
               break;
            }
         }
         if(flag)cnt++;
      }
      cout << cnt << "\n";
   }
   return 0;
}