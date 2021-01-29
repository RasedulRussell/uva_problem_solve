#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 10000
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

///11003_Boxes.cpp

class box{
public:
    int weight, load;
    box(int weight, int load){
        this->weight = weight;
        this->load = load;
    }
};

vector<box>boxes;
int dp[1003][3003][2];

int fun(int pos, int loadBalance, bool start){
    if(pos == boxes.size()){
        if(loadBalance >= 0){
            return 0;
        }
        return -INF;
    }
    if(loadBalance < 0){
        return -INF;
    }
    if(start == 1 && loadBalance == 0){
        return 0;
    }
    if(dp[pos][loadBalance][start] != -1) return dp[pos][loadBalance][start];
    int ans = fun(pos+1, loadBalance, start);
    if(start == 1){
        ans = max(ans, 1+fun(pos+1, min((loadBalance-boxes[pos].weight), boxes[pos].load), 1));
    }else{
        ans = max(ans, 1+fun(pos+1, boxes[pos].load, 1));
    }
    return dp[pos][loadBalance][start] = ans;
}

int32_t main(){
    int n;
    while(cin >> n && n){
        boxes.clear();
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++){
            int w, l;
            cin >> w >> l;
            boxes.push_back(box(w, l));
        }
        cout << fun(0, 0, 0) << "\n";
    }
    return 0;
}