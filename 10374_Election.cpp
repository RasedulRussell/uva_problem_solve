#include<iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <utility>
#include <queue>
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

///10374_Election.cpp

int main(){
   int cs, votar, prarthi;
   string s;
   char partyName[85];
   char prarthiName[85];

   scanf("%d", &cs);

   while(cs--){
      map<string, pair<int, string> >mp;
      scanf("%d\n", &prarthi);
      while(prarthi--){
         gets(prarthiName);
         gets(partyName);
         mp[(string)(prarthiName)] = pair<int, string>(0, (string)(partyName));
      }
      scanf("%d\n", &votar);
      while(votar--){
         gets(prarthiName);
         s = string(prarthiName);
         if(mp.count(s)){
            mp[s] = pair<int, string>(mp[s].first+1, mp[s].second);
         }
      }
      int mx = -1, mxn = 0;
      string ans = "";
      for(auto x : mp){
         if(x.second.first > mx){
            mxn = 1;
            mx = x.second.first;
            ans = x.second.second;
         }else if(x.second.first == mx){
            mxn++;
         }
      }
      if(mxn > 1 || mx < 0){
         printf("tie\n");
      }else{
         printf("%s\n", ans.data());
      }
      if(cs){
         printf("\n");
      }
   }
   
   return 0;
}