#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 105
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     EPS 1e-9

///639_Don’t_Get Rooked.cpp

int32_t main(){
    int n;
    while(cin >> n && n){
        char grid[n][n];
        vector<pii>valid;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
                if(grid[i][j] == '.'){
                    valid.push_back({i,j});
                }
            }
        }
        int sz = valid.size();
        int ans = 0;
        for(int mask = 1; mask < (1 << sz); mask++){
            char tempGrid[n][n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    tempGrid[i][j] = grid[i][j];
                }
            }
            int cnt = 0;
            for(int i = 0; i < sz; i++){
                if((mask & (1 << i))){
                    cnt++;
                    pii point = valid[i];
                    tempGrid[point.first][point.second] = 'Q';
                }
            }
            bool flag = true;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(tempGrid[i][j] == 'Q'){
                        int r = i, c = j+1;
                        while(c < n){
                            if(tempGrid[r][c] == 'Q'){
                                flag = false;
                                break;
                            }
                            if(tempGrid[r][c] == 'X')break;
                            c++;
                        }
                        r = i; c = j-1;
                        while(c >= 0){
                            if(tempGrid[r][c] == 'Q'){
                                flag = false;
                                break;
                            }
                            if(tempGrid[r][c] == 'X')break;
                            c--;
                        }
                        r = i-1; c = j;
                        while(r >= 0){
                            if(tempGrid[r][c] == 'Q'){
                                flag = false;
                                break;
                            }
                            if(tempGrid[r][c] == 'X')break;
                            r--;
                        }
                        r = i+1; c = j;
                        while(r < n){
                            if(tempGrid[r][c] == 'Q'){
                                flag = false;
                                break;
                            }
                            if(tempGrid[r][c] == 'X')break;
                            r++;
                        }
                    }
                }
            }
            if(flag){
                ans = max(ans, cnt);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}