#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///978_Lemmings_Battle.cpp

int main(){
   __FastIO;
   int cs;
   cin >> cs;
   while(cs--){
      int B, SG, SB;
      cin >> B >> SG >> SB;
      priority_queue<int> green, blue;
      for(int i = 0; i < SG; i++){
         int val; cin >> val;
         green.push(val);
      }
      for(int i = 0; i < SB; i++){
         int val; cin >> val;
         blue.push(val);
      }

      while(!green.empty() && !blue.empty()){
         int fild = min(B, min((int)green.size(), (int)blue.size()));
         vector<int>gg, bb;
         for(int i = 0; i < fild; i++){
            int g = green.top(); green.pop();
            int b = blue.top(); blue.pop();
            if(g == b) continue;
            if(g > b){
               gg.push_back(g - b);
            }else{
               bb.push_back(b - g);
            }
         }
         for(int val : gg){
            green.push(val);
         }
         for(int val : bb){
            blue.push(val);
         }
      }
      if(green.size() == 0 && blue.size() == 0){
         cout << "green and blue died\n";
      }else if(green.size() > 0){
         cout << "green wins\n";
         while(!green.empty()){
            cout << green.top() << "\n";
            green.pop();
         }
      }else{
         cout << "blue wins\n";
         while(!blue.empty()){
            cout << blue.top() << "\n";
            blue.pop();
         }
      }
      if(cs){
         cout << "\n";
      }
   }
   return 0;
}