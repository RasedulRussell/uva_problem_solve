#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1000005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11554_Hapless_Hedonism.cpp

int inc[MAX];
int f[MAX];
int g[MAX];

void process(){
    int i = 7;
    inc[6] = 2;
    int val = 3;
    while(i < MAX){
        inc[i++] = val;
        inc[i++] = val++;
    }
    f[6] = 4;
    for(int i = 7; i < MAX; i++){
        f[i] = f[i-1] + inc[i-1];
    }
    g[3] = g[2] = g[1] = 0;
    g[4] = 1;
    g[5] = 3;
    for(int i = 6; i < MAX; i++){
        g[i] = g[i-1] + f[i];
    }
}

int32_t main(){
    process();
    int cs;
    cin >> cs;
    while(cs--){
        int n;
        cin >> n;
        cout << g[n] << "\n";
    }
    return 0;
}