#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 120
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11480_Jimmys_Balls.cpp

int32_t main(){
   int n, cs = 1;
   while(cin >> n && n){
       int ans = 0;
       for(int blue = 1; blue <= n; blue++){
           int remain = n - (3 * blue);
           if(remain <= 2){
               break;
           }
           ans = ans + (remain / 2);
           if(remain % 2 == 0)ans--;
       }
       cout << "Case " << cs++ << ": " << ans << "\n";
   }
    return 0;
}