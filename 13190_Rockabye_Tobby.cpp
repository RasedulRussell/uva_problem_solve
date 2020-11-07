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

///13190_Rockabye_Tobby.cpp

struct node{
   string name;
   int next, id, inc;
   bool operator<(node other)const{
      if(other.next != next){
         return next > other.next;
      }
      return id > other.id;
   }
};

int main(){
   __FastIO;
   int tc;
   cin >> tc;
   while(tc--){
      int n, k;
      priority_queue<node>pq;
      cin >> n >> k;
      for(int i = 0; i < n; i++){
         node temp;
         cin >> temp.name >> temp.inc;
         temp.next = temp.inc;
         temp.id = i;
         pq.push(temp);
      }
      while(k--){
         node temp = pq.top();
         pq.pop();
         cout << temp.next << " " << temp.name << "\n";
         temp.next += temp.inc;
         pq.push(temp);
      }
   }
   return 0;
}