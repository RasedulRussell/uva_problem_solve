#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 10000
#define MAX 45
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int x[2] = {+1, +1};
int y[2] = {+1, -1};

int grid[44][44][22][2];
int exactPeek;
int N, K;

int fun(int nowx, int nowy, int peek, int chance){
    if(nowx == 2*N && nowy == 0){
        if(peek == exactPeek)return 1;
        return 0;
    }
    if(peek > exactPeek || nowx >= 2*N || nowy < 0 || nowy >= 44)return 0;
    if(grid[nowx][nowy][peek][chance] != -1)return grid[nowx][nowy][peek][chance];
    int ans = 0;
    for(int i = 0; i < 2; i++){
        int newX = nowx + x[i];
        int newY = nowy + y[i];
        int tpeek = peek;
        int tchance = 0;
        if(chance == 1 && newY+1 == nowy){
            tpeek++;
        }
        if(newY == K && nowy < newY){
            tchance = 1;
        }
        ans += fun(newX, newY, tpeek, tchance);
    }
    return grid[nowx][nowy][peek][chance] = ans;
}


int32_t main(){
    __FastIO;
    while(cin >> N >> exactPeek >> K){
        memset(grid, -1, sizeof grid);
        cout << fun(0, 0, 0, 0) << "\n";
    }
    return 0;
}

/*
3 1 2 -> 2
10 3 2 -> 2002
*/