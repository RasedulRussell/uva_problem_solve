#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 2
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10518_How_Many_Calls.cpp

struct Matrix{
    int mat[MAX][MAX];
};
int MOD;

Matrix matrixMultiple(Matrix a, Matrix b){
    Matrix ans;
    int k;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            for(ans.mat[i][j] = k = 0; k < MAX; k++){
                ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % MOD) % MOD;
            }
        }
    }
    return ans;
}

Matrix matrixExpo(Matrix base, int n){
    Matrix ans;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            ans.mat[i][j] = (i == j);
        }
    }
    if(n < MAX)return base;
    while(n){
        if(n & 1){
            ans = matrixMultiple(base, ans);
        }
        base = matrixMultiple(base, base);
        n >>= 1;
    }
    return ans;
}

int32_t main(){
    __FastIO;
    int n;
    int cs = 1; 
    while(cin >> n >> MOD){
        if(n == 0 && MOD == 0)break;
        Matrix base;
        base.mat[0][0] = 0;
        base.mat[0][1] = base.mat[1][0] = base.mat[1][1] = 1;
        base = matrixExpo(base, n);
        int ans = (2 * (base.mat[0][0] + base.mat[0][1]) % MOD) % MOD;
        ans = ans - 1;
        if(ans < 0){
            ans += MOD;
        }
        cout << "Case " << cs++ << ": " << n << " " << MOD << " " << ans << "\n";
    }
    return 0;
}