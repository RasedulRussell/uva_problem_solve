#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1000005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10164_Number_Game.cpp

bool isFount = true;
int N;
vector<int>container;
int input[3000];
int dp[3000];

void fun(int pos, int cnt, int sum){
    if(cnt == N){
        if(sum % N == 0){
            isFount = true;
            cout << "Yes\n";
            for(int i = 0; i < N; i++){
                if(i)cout << " ";
                cout << dp[i];
            }
            cout << "\n";
        }
        return;
    }
    if(pos >= (2 * N - 1))return;
    if(isFount)return;
    dp[cnt] = input[pos];
    fun(pos+1, cnt+1, sum+input[pos]);
    fun(pos+1, cnt, sum);
    return;
}

int32_t main(){
    while(cin >> N && N){
        for(int i = 0; i < (2 * N - 1); i++){
            cin >> input[i];
        }
        container.resize(N);
        isFount = false;
        fun(0,0,0);
        if(!isFount){
            cout << "No\n";
        }
    }
    return 0;
}