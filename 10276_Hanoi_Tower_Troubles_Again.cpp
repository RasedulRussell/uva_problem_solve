#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 109
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10276_Hanoi_Tower_Troubles_Again.cpp
int N;
bool squreNumber[1000005];
int dp[100000];

int fun(int value, vector<int>hanoi){
    if(dp[value] != -1)return dp[value];
    vector<int> temp = hanoi;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int val = temp[i] + value;
        if(squreNumber[val] == true || temp[i] == 0){
            temp[i] = value;
            ans = max(ans, max(value, fun(value+1, temp)));
        }
    }
    return dp[value] = ans;
}

int32_t main(){
    __FastIO;
    memset(squreNumber, false, sizeof squreNumber);
    for(int i = 1; i*i <= 1000000; i++){
        squreNumber[i*i] = true;
    }
    int cs;
    cin >> cs;
    while(cs--){
        memset(dp, -1, sizeof dp);
        cin >> N;
        vector<int>hanoi(N, 0);
        cout << fun(1, hanoi) << "\n";
    }
    return 0;
}
