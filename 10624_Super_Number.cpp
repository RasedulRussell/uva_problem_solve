#include<bits/stdc++.h>
using namespace std;

#define     int int
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 105
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///10624_Super_Number.cpp

int ans[32];
int n, m;
bool flag = false;

bool check(int *tans, int pos){
    int sum = 0;
    for(int i = 1; i <= pos; i++){
        sum = sum*10 + tans[i];
        sum %= pos;
    }
    return sum;
}

void fun(int tans[], int pos){
    if(pos > m){
        memcpy(ans , tans , sizeof(ans));
        flag = true;
        return ;
    }
    for(int i = 0; i < 10; i++){
        tans[pos] = i;
        if(tans[1] != 0){
            if(pos < n || pos >= n && !check(tans, pos)){
                fun(tans, pos+1);
            }
            if(flag)return;
        }
    }
    return ;
}

int32_t main(){
    int cs = 1;
    int tc;
    scanf("%d", &tc);
    for(int ok = 0; ok < tc; ok++){
        scanf("%d%d", &n, &m);
        flag = false;
        memset(ans, 0, sizeof ans);
        printf("Case %d: ", cs++);
        fun(ans, 1);
        if(!flag){
            printf("-1\n");
        }else{
            for(int i = 1; i <= m; i++){
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}