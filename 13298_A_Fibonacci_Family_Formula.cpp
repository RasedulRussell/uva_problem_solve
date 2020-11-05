#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 10000
#define MAX 104
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

/// 13298_A_Fibonacci_Family_Formula.cpp

int K, N;
struct matrix{
    int mat[MAX][MAX];
};

matrix matrixMul(matrix a, matrix b){
    matrix ans;
    int i, j, k;
    for(int i = 0; i < K; i++){
        for(j = 0; j < K; j++){
            for(ans.mat[i][j] = k = 0; k < K; k++){
                ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % MOD) % MOD;
            }
        }
    }
    return ans;
}

matrix matrixExpo(matrix base, int n){
    matrix ans;
    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            ans.mat[i][j] = (i == j);
        }
    }
    while(n){
        if(n & 1){
            ans = matrixMul(ans, base);
        }
        base = matrixMul(base, base);
        n >>= 1;
    }
    return ans;
}

int32_t main(){
    while(cin >> K >> N){
        if(N == 0 && K == 0)break;
        matrix base;
        memset(base.mat, 0, sizeof base.mat);
        ///base.mat[0][1] = 1;
        for(int i = 0; i < K - 1; i++){
            base.mat[i][i+1] = 1;
        }
        for(int i = 0; i < K; i++){
            base.mat[K-1][i] = 1;
        }
        int baseValue[K];
        baseValue[0] = baseValue[1] = 1;
        int temp = 2;
        for(int i = 2; i < K; i++){
            baseValue[i] = 0;
            for(int j = 0; j < i; j++){
                baseValue[i] += baseValue[j];
                baseValue[i] = baseValue[i] % MOD;
            }
        }
        if(N < K){
            cout << baseValue[N] << "\n";
            continue;
        }
        base = matrixExpo(base, N);
        int ans = 0, j = 0;
        for(int i = 0; i < K; i++){
            ans = (ans + (baseValue[i] * base.mat[0][j++]) % MOD) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
5 5
3 4
2 3
7 0
0 0

16
7
3
1
*/