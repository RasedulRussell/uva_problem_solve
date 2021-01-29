#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///601_The_PATH.cpp

/// W first colam to last colam
/// B first row to last row

int N;
char target;
char grid[82][82];
bool visit[82][82];
bool visit2[82][82][2];

void dfs(int r, int c){
    if(r < 0 || r >= N || c < 0 || c >= N || visit[r][c] == true || grid[r][c] != target){
        return;
    }
    visit[r][c] = true;
    dfs(r-1, c);
    dfs(r+1, c);
    dfs(r, c+1);
    dfs(r, c-1);
    return;
}

void dfs(int r, int c, int ok){
    if(ok < 0 || r < 0 || r >= N || c < 0 || c >= N || visit2 [r][c][ok] == true){
        return;
    }
    if(grid[r][c] != target && grid[r][c] != 'U'){
        return;
    }
    int tempOk = ok;
    if(grid[r][c] == 'U'){
        tempOk -= 1;
    }
    if(tempOk < 0){
        return;
    }
    visit2[r][c][tempOk] = true;
    dfs(r-1, c, tempOk);
    dfs(r+1, c, tempOk);
    dfs(r, c-1, tempOk);
    dfs(r, c+1, tempOk);
    return;
}

int32_t main(){
    __FastIO;
    while(cin >> N && N){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> grid[i][j];
            }
        }
        bool flag = false;
        for(int i = 0; i < N; i++){
            target = 'W';
            if(grid[i][0] == target){
                memset(visit, false, sizeof visit);
                dfs(i, 0);
                for(int j = 0; j < N; j++){
                    if(visit[j][N-1]){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            cout << "White has a winning path.\n";
            continue;
        }
        for(int i = 0; i < N; i++){
            target = 'B';
            if(grid[0][i] == target){
                memset(visit, false, sizeof visit);
                dfs(0, i);
                for(int j = 0; j < N; j++){
                    if(visit[N-1][j]){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        if(flag){
            cout << "Black has a winning path.\n";
            continue;
        }
        for(int i = 0; i < N; i++){
            target = 'W';
            if(grid[i][0] == target || grid[i][0] == 'U'){
                memset(visit2, false, sizeof visit2);
                dfs(i, 0, 1);
                for(int j = 0; j < N; j++){
                    if(visit2[j][N-1][0] == true || visit2[j][N-1][1] == true){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        if(flag){
            cout << "White can win in one move.\n";
            continue;
        }
        for(int i = 0; i < N; i++){
            target = 'B';
            if(grid[0][i] == target || grid[0][i] == 'U'){
                memset(visit2, false, sizeof visit2);
                dfs(0, i, 1);
                for(int j = 0; j < N; j++){
                    if(visit2[N-1][j][0] == true || visit2[N-1][j][1] == true){
                        flag = true; break;
                    }
                }
            }
            if(flag)break;
        }
        if(flag){
            cout << "Black can win in one move.\n";
            continue;
        }
        cout << "There is no winning path.\n";
    }
    return 0;
}