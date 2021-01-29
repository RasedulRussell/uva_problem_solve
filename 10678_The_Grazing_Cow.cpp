#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 80
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10678_The_Grazing_Cow.cpp

int32_t main(){
   int cs;
   cin >> cs;
   while(cs--){
      double D, L;
      cin >> D >> L;
      D = D / 2.0;
      double a = L / 2.0;
      double b = sqrt(a * a - D * D);
      double area = M_PI * a * b;
      cout << fixed << setprecision(3) << area << "\n";
   }
}