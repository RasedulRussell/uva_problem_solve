#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 200003
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///12337_Bobs_Beautiful_Balls.cpp

int r[4] = {0, 1, 0, -1};
int c[4] = {1, 0, -1, 0};

char grid[110][110];
int N, M;

bool check(){
    for(int i = 0; i < M; i++){
        char ch = grid[0][i];
        for(int j = 0; j < N; j++){
            if(grid[j][i] == ch){
                continue;
            }
            return false;
        }
    }
    return true;
}

int32_t main(){
    int  cs = 1, tc;
    cin >> tc;
    while(tc--){
        string input;
        cin >> input;
        int sz = input.size();
        int ans = INT_MAX;
        int direction = 0;
        for(int i = 2; i < sz; i++){
            int x = 0, y = -1;
            if(sz % i == 0){
                N = i;
                M = sz / i;
                for(int j = 0; j < N; j++){
                    for(int k = 0; k < M; k++){
                        grid[j][k] = '.';
                    }
                }
                int j = 0;
                while(j < sz){
                    int newx = x + r[direction];
                    int newy = y + c[direction];
                    if(newx >= 0 && newx < N && newy >= 0 && newy < M && grid[newx][newy] == '.'){
                        grid[newx][newy] = input[j];
                        x = newx;
                        y = newy;
                        j++;
                    }else{
                        direction++;
                        direction %= 4;
                    }
                }
                if(check()){
                    ans = min(ans, N+M);
                }
            }
        }
        if(ans == INT_MAX)ans = -1;
        cout << "Case " << cs++ << ": " << ans << "\n";
    }
    return 0;
}