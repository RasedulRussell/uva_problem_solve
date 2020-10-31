#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"
#define nll cout << "\n"
#define ll long long
#define MAX 500009
#define log_size 18
#define MOD 1000000007
#define INF 10000000000
#define ii pair<ll,ll>
#define presion cout << fixed << setprecision(6)

int r[4] = {-1, 1, 0, 0};
int c[4] = {0, 0, 1, -1};
vector<int>sequence;
int grid[105][105];
bool visit[105][105];
int n, m;

void process(){
   sequence.push_back(0);
   for(int i = 1; i <= 100; i++){
      for(int j = 1; j <= i; j++){
         ////cout << j <<  " ";
         sequence.push_back(j);
      }
   }
   return;
}

int ansx, ansy, ansxx, ansyy;
int x1, y, x2, y2;

bool fun(int row, int colam, int pos){
   if(row == n-1){
      if(y < ansy){
        ansy = y;
        ansyy = colam;
      }else if(ansy == y){
          ansyy = min(ansyy, colam);
      }
      return true;
   }
   bool flag = false;
   for(int j = 0; j < 4; j++){
      int nr = row + r[j];
      int nc = colam + c[j];
      if(nr < 0 || nr >= n || nc < 0 || nc >= m || visit[nr][nc] || grid[nr][nc] != sequence[pos]) continue;
      visit[nr][nc] = true;
      if(fun(nr, nc, pos+1) == true){
         flag |= true;
      }else{
         visit[nr][nc] = false;
      }
   }
   visit[row][colam] = false;
   return flag;
}

int main(){
   __FastIO;
   process();
   int tc, cs = 0;
   cin >> tc;
   while(tc--){
      ansx = 1000;
      ansxx = ansy = ansyy = 1000;
      if(cs){
         cout << "\n";
      }
      cs = 1;
      cin >> n >> m;
      for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
            cin >> grid[i][j];
         }
      }
      bool check = false;
      for(int i = 0; i < m; i++){
         if(grid[0][i] == 1){
            ////cout << i << "\n";
            memset(visit, false, sizeof visit);
            x1 = 0; y = i;
            visit[0][i] = true;
            check = fun(0, i, 2);
         }
      }
      cout << "1 " << ansy+1 << "\n";
      cout << n << " " << ansyy+1 << "\n"; 
   }
   return 0;
}