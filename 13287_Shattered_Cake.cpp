#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define INF 10000
#define MAX 10001
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
   ull w;
   while(cin >> w){
       ull totalArea = 0ull;
       int n;
       cin >> n;
       while(n--){
           int wi, li;
           cin >> wi >> li;
           totalArea += (wi * li);
       }
       cout << totalArea / w << "\n";
   }
   return 0;
}