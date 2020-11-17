#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 120
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///164_String_Computer.cpp

int dp[40][40];
string x,y;

int min(int a, int b, int c){
    return min(a, min(b, c));
}

void process(){
    int n = x.size();
    int m = y.size();
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0){
                dp[i][j] = j;
            }else if(j == 0){
                dp[i][j] = i;
            }else if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min(
                    dp[i-1][j-1],   /// change
                    dp[i-1][j],     /// delete
                    dp[i][j-1]      //insert
                );
            }
        }
    }
}

string processor(){
    string ans = "";
    int i = x.size();
    int j = y.size();

    while(i || j){
        if(x[i-1] == y[j-1]){
            i--;j--;
            continue;
        }
        if(i > 0 && dp[i][j] == dp[i-1][j] + 1){
            char ch = x[i-1];
            string idx = to_string(i);
            if(idx.size() == 1){
                idx = "0" + idx;
            }
            ans = ans + "D" + ch + idx;
            x.erase(i-1, 1);
            i--;
        }else if(j > 0 && dp[i][j] == dp[i][j-1] + 1){
            string idx = to_string(i+1);
            if(idx.size() == 1){
                idx = "0" + idx;
            }
            char ch = y[j-1];
            ans = ans + "I" + ch + idx;
            x.insert(i, 1, y[j-1]);
            j--;
        }else if(i > 0 && j > 0){
            string idx = to_string(i);
            if(idx.size() == 1){
                idx = "0" + idx;
            }
            x[i-1] = y[j-1];
            ans = ans + "C" + y[j-1] + idx;
            i--;j--;
        }
    }
    return ans;
}

int32_t main(){
    while(cin >> x){
        if(x == "#")break;
        cin >> y;
        process();
        ///cout << dp[x.size()][y.size()] << "\n";
        string ans = processor();
        ans = ans + "E";
        cout << ans << "\n";
    }
    return 0;
}