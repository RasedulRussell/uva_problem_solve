#include<bits/stdc++.h>
using namespace std;

#define int int
#define INF 1000000
#define MAX 1026
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10360_Rat_Attack.cpp

int table[MAX][MAX];

int d, n, c;

void ini(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            table[i][j] = 0;
        }
    }
    return;
}

void process(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(j){
                table[i][j] += table[i][j-1];
            }
        }
    }
    for(int i = 0; i < MAX;  i++){
        for(int j = 0; j < MAX; j++){
            if(j){
                table[j][i] += table[j-1][i];
            }
        }
    }
    return;
}

int main(){
    __FastIO;
    int cs;
    cin >> cs;
    while(cs--){
        ini();
        cin >> d >> n;
        while(n--){
            int a, b, val;
            cin >> a >> b >> val;
            table[a][b] = val;
        }
        process();
        int mx = -1, ansr = -1, ansc = -1;
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                int r = i + (2 * d);
                int c = j + (2 * d);
                if(r >= MAX || c >= MAX)continue;
                int value = table[r][c];
                if((j-1) >= 0){
                    value -= table[r][j-1];
                }
                if((i-1) >= 0){
                    value -= table[i-1][c];
                }
                if((i-1) >= 0 && (j-1) >= 0){
                    value += table[i-1][j-1];
                }
                if(value > mx){
                    mx = value;
                    ansr = i+d;
                    ansc = j+d;
                }
            }
        }
        cout << ansr << " " << ansc << " " << mx << "\n";
    }
    return 0;
}