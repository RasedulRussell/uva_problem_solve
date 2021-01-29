#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 7000
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10670_Work_Reduction.cpp

class company{
public:
   string name;
   int costA, costB;
   company(string name, int costA, int costB){
      this->name = name;
      this->costA = costA;
      this->costB = costB;
   }
};

company encrypt(string input){
   string name = "";
   int a = 0;
   int b = 0;
   int i = 0;
   while(input[i] != ':'){
      name.push_back(input[i++]);
   }
   i++;
   while(input[i] != ','){
      a = (a*10) + (input[i++] - '0');
   }
   i++;
   while(i < input.size()){
      b = (b*10) + (input[i++] - '0');
   }
   ///cout << name << " " << a << " " << b << "\n";
   company temp = company(name, a, b);
   return temp;
}

int process(int n, int m, int a, int b){
   int ans = 0;
   while(n > m){
      int half = n / 2;
      if(half < m){
         int diff = (n - m);
         ans += diff * a;
         n = m;
      }else{
         int diff = n - half;
         ans += min(diff*a, b);
         n = half;
      }
   }
   return ans;
}

int32_t main(){
   __FastIO;
   int cs =  1;
   int tc;
   cin >> tc;
   while(tc--){
      vector<company>companys;
      int n, m, l;
      cin >> n >> m >> l;
      for(int i = 0; i < l; i++){
         string line;
         cin >> line;
         companys.push_back(encrypt(line));
      }
      vector<pair<string, int>>ans;
      for(int i = 0; i < l; i++){
         int temp = process(n, m, companys[i].costA, companys[i].costB);
         ans.push_back({companys[i].name, temp});
      }
      sort(ans.begin(), ans.end(), [](pair<string, int>a, pair<string, int>b){
         if(a.second == b.second){
            return a.first < b.first;
         }
         return a.second < b.second;
      });
      cout << "Case " << cs++ << "\n";
      for(int i = 0; i < ans.size(); i++){
         cout << ans[i].first << " " << ans[i].second << "\n";
      }
   }
   return 0;
}