#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 1005
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10687_Monitoring_the_Amazon.cpp

vector<int>adj[MAX];
bool visit[MAX];
int N;

class point{
public:
   double x, y, distances;
   int id;
   point(double x, double y, double distances, int id){
      this->x = x;
      this->y = y;
      this->distances = distances;
      this->id = id;
   }
   bool operator<(point other)const{
      if(other.distances == distances){
         if(other.x != x){
            return x < other.x;
         }
         return y < other.y;
      }
      return distances < other.distances;
   }
};

double distances(double x1, double y1, double x2, double y2){
   double diff1 = x1 - x2;
   double diff2 = y1 - y2;
   return sqrt(diff1 * diff1 + diff2 * diff2);
}

void constructGraph(vector<pair<double, double>>& coordinate){
   for(int i = 0; i < N; i++){
      vector<point>points;
      for(int j = 0; j < N; j++){
         if(i == j)continue;
         points.push_back(point(coordinate[j].first, coordinate[j].second, 
                              distances(coordinate[i].first, coordinate[i].second, coordinate[j].first, coordinate[j].second), j));
      }
      sort(points.begin(), points.end());
      if(points.size() >= 2){
         adj[i].push_back(points[0].id);
         adj[i].push_back(points[1].id);
      }else if(points.size() == 1){
         adj[i].push_back(points[0].id);
      }
   }
}

void INI(){
   for(int i = 0; i < MAX; i++){
      visit[i] = false;
      adj[i].clear();
   }
   return;
}

void dfs(int u){
   visit[u] = true;
   for(int v : adj[u]){
      if(visit[v]) continue;
      dfs(v);
   }
   return;
}

int32_t main(){
   while(cin >> N && N){
      vector<pair<double, double>> coordinate(N);
      for(int i = 0; i < N; i++){
         cin >> coordinate[i].first >> coordinate[i].second;
      }
      
      INI();
      constructGraph(coordinate);
      dfs(0);
      
      bool ans = true;
      for(int i = 0; i < N; i++){
         ans &= visit[i];
      }
      if(ans){
         cout << "All stations are reachable.\n";
      }else{
         cout << "There are stations that are unreachable.\n";
      }
   }
   return 0;
}