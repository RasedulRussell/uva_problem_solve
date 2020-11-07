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

///315_Network.cpp

vector<int>adj[MAX];
bool visit[MAX];

void dfs(int u){
   visit[u] = true;
   for(int v : adj[u]){
      if(visit[v])continue;
      dfs(v);
   }
   return;
}

int main(){
   bool foo = 0;
   ///__FastIO;
   int N;
   while(cin >> N && N){
      for(int i = 0; i < MAX; i++){
         adj[i].clear();
      }
      ///cin.ignore();
      string line;
      while(getline(cin, line)){
         if(line == "0")break;
         stringstream st;
         st << line;
         int u, v;
         st >> u;
         while(st >> v){
            adj[u].push_back(v);
            adj[v].push_back(u);
         }
         st.clear();
      }
      if(N <= 1){
         cout << "0\n"; continue;
      }
      int cnt = 0;
      for(int i = 1; i <= N; i++){
         memset(visit, false, sizeof visit);
         visit[i] = true;
         if(i == 1){
            dfs(2);
         }else{
            dfs(1);
         }
         for(int j = 1; j <= N; j++){
            if(!visit[j]){
               cnt++;
               break;
            }
         }        
      }
      cout << cnt << "\n";
   }
   return 0;
}