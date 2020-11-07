#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11995 I Can Guess the Data Structure.cpp

int main(){
   __FastIO;
   int n = 0;
   while(cin >> n){
      queue<int>q;
      priority_queue<int>pq;
      stack<int>st;
      bool qok = true;
      bool pqok = true;
      bool stok = true;
      while(n--){
         int op, val;
         cin >> op >> val;
         if(op == 1){
            if(qok){
               q.push(val);
            }
            if(pqok){
               pq.push(val);
            }
            if(stok){
               st.push(val);
            }
         }else{
            if(qok){
               if(!q.empty() && q.front() == val){
                  q.pop();
               }else{
                  qok = false;
               }
            }
            if(pqok){
               if(!pq.empty() && pq.top() == val){
                  pq.pop();
               }else{
                  pqok = false;
               }
            }
            if(stok){
               if(!st.empty() && st.top() == val){
                  st.pop();
               }else{
                  stok = false;
               }
            }
         }
      }
      int cnt = 0;
      if(pqok)cnt++;
      if(qok)cnt++;
      if(stok)cnt++;
      if(cnt == 0){
         cout << "impossible\n";
      }else if(cnt > 1){
         cout << "not sure\n";
      }else if(qok){
         cout << "queue\n";
      }else if(pqok){
         cout << "priority queue\n";
      }else{
         cout << "stack\n";
      }
   }
   return 0;
}