#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11170_Cos(NA).cpp

int32_t main(){
    ///__FastIO;
    int memo[55][55];
    memset(memo, 0, sizeof memo);
    memo[0][0] = 1;
    memo[1][1] = 1;
    for(int i = 2; i <= 50; i++){
        for(int j = 0; j <= 50; j++){
            memo[i][j+1] = 2*memo[i-1][j];
        }
        for(int j = 0; j <= 50; j++){
            memo[i][j] -= memo[i-2][j];
        }
    }
    int n;
    while(cin >> n && n){
        bool flag = true;
        if(n == 1){
            cout << "Cos(A)\n";
            continue; 
        }
        for(int i = 54; i >= 0; i--){
            if(memo[n][i] == 0) continue;
            int val = memo[n][i];
            if(flag){
                if(val > 1){
                    cout << val;
                }
                cout << "Cos";
                if(i > 1){
                    cout << "^" << i << "(A)";
                }
                flag = false;
                continue;
            }
            if(i == 0){
                if(val > 0){
                    cout << "+" << val;
                }else{
                    cout << val;
                }
                continue;
            }
            bool sign = true;
            if(val < 0){
                val *= -1;
                sign = false;
            }
            if(sign){
                cout << "+";
            }else{
                cout << "-";
            }
            if(val > 1){
                cout << val;
            }
            cout << "Cos";
            if(i>1){
                cout << "^" << i << "(A)";
            }else{
                cout << "(A)";
            }
        }
        cout << "\n";
    }
    return 0;
}