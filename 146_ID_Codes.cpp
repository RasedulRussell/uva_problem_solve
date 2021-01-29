#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 7000
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///146_ID_Codes.cpp

int32_t main(){
   __FastIO;
   string sequence;
   while(cin >> sequence && sequence != "#"){
      bool flag = next_permutation(sequence.begin(), sequence.end());
      if(flag){
         cout << sequence << "\n";
      }else{
         cout << "No Successor\n";
      }
   }
   return 0;
}