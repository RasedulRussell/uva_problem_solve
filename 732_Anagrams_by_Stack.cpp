#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 70
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define  dbg cout << "dbg\n"

///732_Anagrams_by_Stack.cpp

string a, b;
vector<string>ans;

void utilFun(int firstIdx, int secondIdx, stack<char>st, string operation){
   if(firstIdx == a.size()){
      while(st.size() > 0 && st.top() == b[secondIdx++]){
         operation = operation + "o";
         st.pop();
      }
      if(st.size() == 0 && secondIdx == b.size()){
         ans.push_back(operation);
      }
      return;
   }
   if(secondIdx == b.size())return;
   if(st.size() > 0 && b[secondIdx] == st.top()){
      char ch = st.top();
      st.pop();
      utilFun(firstIdx, secondIdx+1, st, (operation+"o"));
      st.push(ch);
   }
   st.push(a[firstIdx]);
   utilFun(firstIdx+1, secondIdx, st, (operation+"i"));
   st.pop();
}

int32_t main(){
   __FastIO;
   while(cin >> a >> b){
      ans.clear();
      stack<char>st;
      utilFun(0, 0, st, "");
      sort(ans.begin(), ans.end());
      cout << "[\n";
      for(string s : ans){
         cout << s[0];
         for(int i = 1; i < s.size(); i++){
            cout << " " << s[i];
         }
         cout << "\n";
      }
      cout << "]\n";
   }
   return 0;
}