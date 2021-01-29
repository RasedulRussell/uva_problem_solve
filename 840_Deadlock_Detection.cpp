#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 70
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define  dbg cout << "dbg\n"

///840_Deadlock_Detection.cpp

vector<int>adj[MAX];
vector<int>radj[MAX];
vector<int>order;
vector<int>scc;
bool visit[MAX];

/// input processing
map<char, int>mp;
map<int, char>rmp;
set<int>currentNode;
int N;

void dfs(int u){
   visit[u] = true;
   for(int v : adj[u]){
      if(visit[v]) continue;
      dfs(v);
   }
   order.push_back(u);
   return;
}

void stronglyConnectedComponent(int u){
   visit[u] = true;
   for(int v : radj[u]){
      if(visit[v]) continue;
      stronglyConnectedComponent(v);
   }
   scc.push_back(u);
   return;
}

vector<int>sccGraph[MAX];
stack<int>cycle;
set<int>blockSet;
bool badNode[MAX];
int sourse;
vector<string>deadLocs;

void getCycle(stack<int>st){
   int u = st.top();
   string cle = "";
   cle.push_back(rmp[u]);
   st.pop();

   while(!st.empty()){
      u = st.top();
      st.pop();
      cle.push_back('-');
      cle.push_back(rmp[u]);
   }
   reverse(cle.begin(), cle.end());
   deadLocs.push_back(cle);
   return;
}

void cycleFind(int u){
   cycle.push(u);
   blockSet.insert(u);
   for(int v : sccGraph[u]){
      if(badNode[v]) continue;
      if(blockSet.find(v) == blockSet.end()){
         cycleFind(v);
      }else if(v == sourse){
         cycle.push(sourse);
         getCycle(cycle);
         cycle.pop();
      }
   }
   cycle.pop();
   blockSet.erase(u);
   return;
}

void constructScc(){
   for(int i = 1; i < MAX; i++){
      sccGraph[i].clear();
   }
   memset(badNode, false, sizeof badNode);
   sort(scc.begin(), scc.end());

   for(int i : scc){
      for(int v : adj[i]){
         if(find(scc.begin(), scc.end(), v) == scc.end()) continue;
         sccGraph[i].push_back(v);
      }
   }
   for(int i : scc){
      blockSet.clear();
      sourse = i;
      cycleFind(i);
      badNode[i] = true;
   }
   return;
}

void utilFun(){
   deadLocs.clear();
   memset(visit, false, sizeof visit);
   order.clear();
   for(int i : currentNode){
      if(!visit[i]){
         dfs(i);
      }
   }
   memset(visit, false, sizeof visit);
   for(int i = order.size()-1; i >= 0; i--){
      int u = order[i];
      if(!visit[u]){
         scc.clear();
         stronglyConnectedComponent(u);
         if(scc.size() > 1){
            constructScc();
         }
      }
   }
   return;
}

int32_t main(){
   int id = 1;
   for(int i = 0; i < 26; i++){
      char ch = 'A' + i;
      mp[ch] = id;
      rmp[id++] = ch;
   }
   for(int i = 0; i < 26; i++){
      char ch = 'a' + i;
      mp[ch] = id;
      rmp[id++] = ch;
   }
   __FastIO;
   int cs, tc = 0;
   cin >> cs;
   while(cs--){
      if(tc){
         cout << "\n";
      }
      tc = 1;
      ///ini 
      for(int i = 0; i < MAX; i++){
         adj[i].clear();
         radj[i].clear();
      }

      int n, m, Edge, cnt = 1;
      cin >> n >> m >> Edge;

      for(int i = 0; i < Edge; i++){
         string str;
         cin >> str;
         int u = mp[str[0]];
         int v = mp[str[2]];
         adj[u].push_back(v);
         radj[v].push_back(u);
         currentNode.insert(u);
         currentNode.insert(v);
      }

      utilFun(); /// main process
      if(deadLocs.size() > 0){
         sort(deadLocs.begin(), deadLocs.end(), [](string a, string b){
            return a.size() < b.size();
         });
         cout << "YES\n";
         for(string cl : deadLocs){
            cout << cl << "\n";
         }
      }else{
         cout << "NO\n";
      }
   }
   return 0;
}