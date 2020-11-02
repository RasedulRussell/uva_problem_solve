#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 10000
#define MAX 45
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int r[8] = {-1, 0, +1, +1, +1, 0, -1, -1};
int c[8] = {-1, -1, -1, 0, +1, +1, +1, 0};

class node{
    public:
        int x, y, d;
        node(int x, int y, int d){
            this->x = x;
            this->y = y;
            this->d = d;
        }
};

bool grid[9][9];

int32_t main(){
    __FastIO;
    int sx, sy, dx, dy, cx, cy, cs = 1;
    while(cin >> sx >> sy >> dx >> dy >> cx >> cy){
        memset(grid, false, sizeof grid);
        grid[cx][cy] = true;
        
        queue<node>q;
        q.push(node(sx, sy, 0));
        grid[sx][sy] = true;
        int ans = 0;
        while(!q.empty()){
            node temp = q.front();
            q.pop();
            if(temp.x == dx && temp.y == dy){
                ans = temp.d;
                break;
            }
            for(int i = 0; i < 8; i++){
                int x = temp.x + r[i];
                int y = temp.y + c[i];
                int d = temp.d + 1;
                if(x <= 0 || x > 8 || y <= 0 || y > 8 || grid[x][y] == true) continue;
                grid[x][y] = true;
                q.push(node(x, y, d));
            }
        }
        cout << "Case " << cs++ << ": " << ans << "\n";
    }
    return 0;
}