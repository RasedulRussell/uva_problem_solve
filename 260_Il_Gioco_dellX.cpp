#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 205
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///260_Il_Gioco_dellX.cpp

int r[6] = {-1, -1, 0, 0, +1, +1}; ///(i − 1, j − 1),(i − 1, j),(i, j − 1),(i, j + 1),(i + 1, j),(i + l, j + 1)
int c[6] = {-1, 0, -1, +1, 0, +1};

char grid[MAX][MAX];
bool visit[MAX][MAX];
int N;

void dfs(int row, int colam){
   visit[row][colam] = true;
   for(int i = 0; i < 6; i++){
      int newr = row + r[i];
      int newc = colam + c[i];
      if(newr < 0 || newr >= N || newc < 0 || newc >= N || visit[newr][newc] == true || grid[newr][newc] != 'b'){
         continue;
      }
      dfs(newr, newc);
   }
   return;
}

int32_t main(){
   __FastIO;
   int cs = 1;
   while(cin >> N && N){
      for(int i = 0; i < N; i++){
         for(int j = 0; j < N; j++){
            cin >> grid[i][j];
         }
      }
      bool black = false;
      for(int i = 0; i < N; i++){
         if(grid[0][i] == 'b'){
            memset(visit, false, sizeof visit);
            dfs(0, i);
            for(int j = 0; j < N; j++){
               if(visit[N-1][j] == true){
                  black = true; break;
               }
            }
         }
         if(black)break;
      }
      if(black){
         cout << cs++ << " B\n"; 
      }else{
         cout << cs++ << " W\n";
      }
   }
   return 0;
}