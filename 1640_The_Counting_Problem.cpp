#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 200003
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///1640_The_Counting_Problem.cpp

int dp[11][2][2][2][500];
vector<int>Left, Right;
int target;

int fun(int pos, int isStart, int small, int big, int cnt){
    if(pos == Left.size()){
        return cnt;
    }
    if(dp[pos][isStart][small][big][cnt] != -1)return dp[pos][isStart][small][big][cnt];
    int st = small ? Left[pos] : 0;
    int en = big ? Right[pos] : 9;
    int ans = 0;
    for(int i = st; i <= en; i++){
        int newSmall = (Left[pos] == i) ? small : 0;
        int newBig = (Right[pos] == i) ? big : 0;
        int newCnt = cnt;
        int newStart = isStart;
        if(i > 0)newStart = 1;
        if(i == target && newStart){
            newCnt++;
        }
        ans += fun(pos+1, newStart, newSmall, newBig, newCnt);
    }
    return dp[pos][isStart][small][big][cnt] = ans;
}

int32_t main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        if(n > m)swap(n, m);
        Left.clear();
        Right.clear();
        while(n){
            Left.push_back(n % 10);
            n /= 10;
        }
        while(m){
            Right.push_back(m % 10);
            m /= 10;
        }
        while(Left.size() < Right.size()){
            Left.push_back(0);
        }
        reverse(Left.begin(), Left.end());
        reverse(Right.begin(), Right.end());
        vector<int>ans;
        for(int i = 0; i <= 9; i++){
            target = i;
            memset(dp, -1, sizeof dp);
            int val = fun(0, 0, 1, 1, 0);
            ans.push_back(val);
        }
        for(int i = 0; i < 10; i++){
            cout << ans[i];
            if(i != 9){
                cout << " ";
            }else{
                cout << "\n";
            }
        }
    }
    return 0;
}