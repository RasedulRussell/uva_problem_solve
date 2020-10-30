#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define INF 10000
#define MAX 10001
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

string dp[55][55];
char grid[55][55];
int N;

string longestPalindrom(int sourse, int destination){
    if(sourse > destination){
        return "*";
    }
    if(sourse == destination){
        return "";
    }
    if(dp[sourse][destination] != "?"){
        return dp[sourse][destination];
    }
    string ans = "";
    ans = ans + grid[sourse][destination];
    for(int i = sourse+1; i < N; i++){
        if(grid[sourse][i] == '*')continue;
        for(int j = destination-1; j >= 0; j--){
            if(grid[j][destination] == '*') continue;
            if(grid[sourse][i] == grid[j][destination]){
                string t = longestPalindrom(i, j);
                if(t != "*"){
                    string g = grid[sourse][i] + t + grid[j][destination];
                    if(g.size() > ans.size()){
                        ans = g;
                    }else if(g.size() == ans.size()){
                        ans = min(ans, g);
                    }
                }
            }
        }
    }
    return dp[sourse][destination] = ans;
}

int main(){
    __FastIO;
   int tc;
   cin >> tc;
   while(tc--){
       cin >> N;
       for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
               cin >> grid[i][j];
           }
       }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dp[i][j] = "?";
            }
        }

       string ans = longestPalindrom(0, N-1);
       if(ans == "*"){
           cout << "NO PALINDROMIC PATH\n";
       }else{
           cout << ans << "\n";
       }
   }
}

/*
3
5
*ABAC
A*CBD
BC*CB
ABC*A
CDBA*
5
*AXYZ
A*BQR
XB*BT
YQB*A
ZRTA*
4
*AJK
L*BP
GT*A
NMR*
*/