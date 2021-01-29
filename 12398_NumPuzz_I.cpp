#include<bits/stdc++.h>
using namespace std;

#define int int
#define MAX 2000005
#define MOD 1000000007
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"

///12398_NumPuzz_I.cpp

int r[5] = {0, +1, -1, 0, 0};
int c[5] = {0, 0, 0, -1, +1};
map<char, pair<int,int>>grid;

void process(){
    grid['a'] = {0, 0};
    grid['b'] = {0, 1};
    grid['c'] = {0, 2};
    grid['d'] = {1, 0};
    grid['e'] = {1, 1};
    grid['f'] = {1, 2};
    grid['g'] = {2, 0};
    grid['h'] = {2, 1};
    grid['i'] = {2, 2};
    return;
}

int32_t main(){
    int cs = 1;
    process();
    string line;
    while(getline(cin, line)){
        int puzzel[3][3];
        memset(puzzel, 0, sizeof puzzel);
        for(int ch : line){
            if(grid.count(ch) == 0) continue;
            pair<int,int>pos = grid[ch];
            int x = pos.first;
            int y = pos.second;
            for(int i = 0; i < 5; i++){
                int xx = x + r[i];
                int yy = y + c[i];
                if(xx >= 3 || xx < 0 || yy >= 3 || yy < 0)continue;
                puzzel[xx][yy]++;
                puzzel[xx][yy] %= 10;
            }
        }
        ///Case #1:
        cout << "Case #" << cs++ << ":\n";
        for(int i = 0; i < 3; i++){
            cout << puzzel[i][0] << " " << puzzel[i][1] << " " << puzzel[i][2] << "\n";
        }
    }
    return 0;
}