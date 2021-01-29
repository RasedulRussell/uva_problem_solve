#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 7000
#define MOD 1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///1374_Power_Calculus.cpp

int n;
int ans[1004];
bool ok;

void fun(int curr, int limit){
    if(ok == true || curr > limit || ((ans[curr]*(1<<(limit-curr))) < n))return;
    if(curr == limit){
        if(ans[curr] == n){
            ok = true;
        }
        return;
    }
    int last = ans[curr];
    for(int i = 0; i <= curr; i++){
        ans[curr+1] = ans[i] + last;
        fun(curr+1, limit);
    }
    for(int i = 0; i < curr; i++){
        ans[curr+1] = last - ans[i];
        if(ans[curr+1] <= 0) continue;
        fun(curr+1, limit);
    }
}

int fun(){
    if(n == 1){
        return 0;
    }
    ok = false;
    for(int i = 1; i < 30; i++){
        ans[0] = 1;
        fun(0, i);
        if(ok)return i;
    }
    return 0;
}

int32_t main(){
    while(cin >> n && n){
       int an = fun();
       cout << an << "\n";
    }
    return 0;
}