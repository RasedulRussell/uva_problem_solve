#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 120
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10502_Counting_Rectangles.cpp

int table[MAX][MAX];
int N, M;

int solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(j){
                table[i][j] += table[i][j-1];
            }
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(j){
                table[j][i] += table[j-1][i];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = i; k < N; k++){
                for(int l = j; l < M; l++){
                    int sum = table[k][l];
                    if(i-1 >= 0){
                        sum -= table[i-1][l];
                    }
                    if(j-1 >= 0){
                        sum -= table[k][j-1];
                    }
                    if(i-1 >= 0 && j-1 >= 0){
                        sum += table[i-1][j-1];
                    }
                    int sz = (k-i+1)*(l-j+1);
                    if(sz == sum){
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

int32_t main(){
    __FastIO;
    while(cin >> N && N){
        cin >> M;
        for(int i = 0; i < N; i++){
            string str;
            cin >> str;
            for(int j = 0; j < M; j++){
                table[i][j] = ((str[j] == '1') ? 1 : 0);
            }
        }
        cout << solve() << "\n";
    }
    return 0;
}