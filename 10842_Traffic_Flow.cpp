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

///10842_Traffic_Flow.cpp

struct node{
   int u, v, c;
   node(int _u, int _v, int _c) : u(_u), v(_v), c(_c){}
};

int parent[MAX];
vector<node>adj;

int findParent(int u){
   if(parent[u] == u)return u;
   return parent[u] = findParent(parent[u]);
}

int fun(){
   for(int i = 0; i < MAX; i++){
      parent[i] = i;
   }
   sort(adj.begin(), adj.end(),[](node a, node b){
      return a.c> b.c;
   });
   int ans = INT_MAX;
   for(int i = 0; i < adj.size(); i++){
       int u = findParent(adj[i].u);
       int v = findParent(adj[i].v);
       if(u != v){
          ans = min(ans, adj[i].c);
          parent[v] = u;
       }
   }
   return ans;
}

int main(){
   int tc, cs = 1;
   cin >> tc;
   while(tc--){
      adj.clear();
      int n, m;
      cin >> n >> m;
      for(int i = 0; i < m; i++){
         int u, v, c;
         cin >> u >> v >> c;
         adj.push_back(node(u,v,c));
      }
      cout << "Case #" << cs++ << ": " << fun()  << "\n";
   } 
   return 0;
}