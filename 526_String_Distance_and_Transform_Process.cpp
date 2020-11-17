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
#define     MAX 1505
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     con continue

///526_String_Distance_and_Transform_Process.cpp

class Node{
public:
    string operation;
    int idx;
    char ch;
    Node(string operation, char ch, int idx){
        this->idx = idx;
        this->operation = operation;
        this->ch = ch;
    }
};

int dp[100][100];

int min(int x, int y, int z){
    return min(min(x, y), z);
}

int fun(string a, string b, int n, int m){
    if(n == 0){
        return m; ///all all char from b
    }
    if(m == 0){
        return n; /// remove all char from a
    }
    if(dp[n][m] != -1)return dp[n][m];
    if(a[n-1] == b[m-1]){
        return dp[n][m] = fun(a, b, n-1, m-1);
    }else{
        return dp[n][m] = 1 + min(
            fun(a, b, n-1, m),
            fun(a, b, n-1, m-1),
            fun(a, b, n, m-1)
        );
    }
}

int32_t main(){
    string a, b;
    int flag = false;
    while(getline(cin, a)){
        if(flag){
            nll;
        }
        getline(cin, b);
        flag = true;
        int n = a.size();
        int m = b.size();
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0){
                    dp[i][j] = j;
                }else if(j == 0){
                    dp[i][j] = i;
                }else if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(
                        dp[i-1][j-1], ///replace
                        dp[i-1][j], ///remove
                        dp[i][j-1] ///insert
                    );
                }
            }
        }
        
        int i = n, j = m;
        int step = 1;
        cout << dp[n][m] << "\n";
        while(i || j){
            if(a[i-1] == b[j-1]){
                i--;j--;
                continue;
            }
            cout << step++ << " ";
            if(i > 0 && dp[i-1][j]+1 == dp[i][j]){
                cout << "Delete " << i << "\n";
                a.erase(i-1, 1);
                i--;
            }else if(j > 0 && dp[i][j] == dp[i][j-1]+1){
                cout << "Insert " << i+1 << "," << b[j-1] << "\n";
                a.insert(i, 1, b[j-1]);
                j--;
            }else if(i > 0 && j > 0){
                cout << "Replace " << i << "," << b[j-1] << "\n";
                a[i-1] = b[j-1];
                i--;j--;
            }
        }
    }
    return 0;
}