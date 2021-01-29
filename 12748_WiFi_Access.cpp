#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 80
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12748_WiFi_Access.cpp

class router{
public:
   double x, y, range;
   router(double x, double y, double range){
      this->x = x;
      this->y = y;
      this->range = range;
   }
};

double distances(double x1, double y1, double x2, double y2){
   return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

string fun(vector<router> & routers, double x, double y){
   for(int i = 0; i < routers.size(); i++){
      if(distances(routers[i].x, routers[i].y, x, y) <= routers[i].range)return "Yes";
   }
   return "No";
}

int32_t main(){
   __FastIO;
   int cs = 1, tc;
   cin >> tc;
   while(tc--){
      vector<router>routers;
      int n, user;
      cin >> n >> user;
      for(int i = 0; i < n; i++){
         double x, y, range;
         cin >> x >> y >> range;
         routers.push_back(router(x, y, range));
      }
      cout << "Case " << cs++ << ":\n";
      while(user--){
         double x, y;
         cin >> x >> y;
         cout << fun(routers, x, y) << "\n";
      }
   }
}