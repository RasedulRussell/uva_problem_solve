#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///13217_Amazing_Function.cpp

double dp[5];

void process(){
    dp[0] = 5.5957541127251504405264191404215;
    for(int i = 1; i < 5; i++){
        dp[i] = (dp[i-1]*dp[i-1] - 5.0) / (2.0*dp[i-1] + 4.0 );
        ///cout << i << " " << dp[i] << "\n";
    }
}

int32_t main(){
    cout << fixed << setprecision(10);
    process();
    string n;
    while(cin >> n){
        if(n == "0"){
            cout << dp[0] << "\n"; continue;
        }
        if(n == "1"){
            cout << dp[1] << "\n"; continue;
        }
        if(n == "2"){
            cout << dp[2] << "\n"; continue;
        }
        int val = n[n.size() - 1] - '0';
        if(val%2 == 0){
            cout << dp[4] << "\n";
        }else{
            cout << dp[3] << "\n";
        }
    }
    return 0;
}