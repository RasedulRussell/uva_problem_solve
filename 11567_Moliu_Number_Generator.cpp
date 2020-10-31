#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"
#define nll cout << "\n"
#define ll long long
#define MAX 500009
#define log_size 18
#define MOD 1000000007
#define INF 10000000000
#define ii pair<ll,ll>
#define presion cout << fixed << setprecision(6)

int main(){
   __FastIO;
   ll n;
   while(cin >> n){
      int cnt = 0;
      if(n <= 3){
         cout << n << "\n";
         continue;
      }
      vector<char>operation;
      ll N = n;
      while(n){
         if(n%2 == 0){
            operation.push_back('?');
            ///cout << "/\n";
            n = n / 2;
         }else if(n % 4 == 3){
            ///cout << "+\n";
            operation.push_back('+');
            n = n + 1;
         }else{
           /// cout << "-\n";
            operation.push_back('-');
            n = n - 1;
         }
         cnt++;
      }
      reverse(operation.begin(), operation.end());
      if(operation.size() >= 4 && operation[0] == '-' && operation[1] == '?' && operation[2] == '?' && operation[3] == '+'){
         cnt--;
      }
      cout << cnt << "\n";
   }
   return 0;
}