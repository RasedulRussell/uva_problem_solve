#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 55
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


int r[8] = {-1,  0, +1, +1, +1,  0, -1, -1};
int c[8] = {-1, -1, -1,  0, +1, +1, +1, 0};

/// 487_Boggle_Blitz.cpp

char board[MAX][MAX];
int visit[MAX][MAX];
set<string>words;
int N;

void fun(int row, int colam, string str){
    visit[row][colam] = true;
    if(str.size() >= 3){
        words.insert(str);
    }
    for(int i = 0; i < 8; i++){
        int newr = row + r[i];
        int newc = colam + c[i];
        if(newr < 0 || newr >= N || newc < 0 || newc >= N || visit[newr][newc] == true || board[newr][newc] <= board[row][colam]) continue;
        str.push_back(board[newr][newc]);
        fun(newr, newc, str);
        str.pop_back();
        visit[newr][newc] = false;
    }
    visit[row][colam] = false;
    return;
}

int32_t main(){
    int cs, tc = 0;
    cin >> cs;
    while(cs--){
        cin >> N;
        if(tc){
            cout << "\n";
        }
        tc = 1;
        for(int i  = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> board[i][j];
            }
        }
        words.clear();
        memset(visit, false, sizeof visit);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                string str = "";
                str.push_back(board[i][j]);
                fun(i, j, str);
            }
        }
        vector<string>ans; 
        for(string str : words){
            ans.push_back(str);
        }
        sort(ans.begin(), ans.end(), [](string a, string b){
            if(a.size() != b.size()){
                return a.size() < b.size();
            }
            return a < b;
        });
        for(string word : ans){
            cout << word << "\n";
        }
    }
    return 0;
}