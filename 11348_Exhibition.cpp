#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 209
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11348_Exhibition.cpp


int memo[50][10002];
int total[10002];

int32_t main(){
    cout << fixed << setprecision(6);
    int tc, cs = 1;
    cin >> tc;
    while(tc--){
        memset(memo, 0, sizeof memo);
        memset(total, 0, sizeof total);
        int N;
        cin >> N;
        for(int i = 0; i < N; i++){
            int n; cin >> n;
            for(int j = 0; j < n; j++){
                int val; cin >> val;
                memo[i][val]++;
                total[val]++;
            }
        }
        vector<int>unique;
        int totalUnique = 0;
        for(int i = 0; i < N; i++){
            int ok = 0;
            for(int j = 0; j <= 10000; j++){
                if((total[j] - memo[i][j] == 0) && memo[i][j] > 0)ok++;
            }
            unique.push_back(ok);
            totalUnique += ok;
        }
        cout << "Case " << cs++ << ":";
        for(int i = 0; i < unique.size(); i++){
            cout << " " << ((unique[i]*1.0)/(totalUnique*1.0))*100.0 << "%";
        } 
        cout << "\n";
    }
    return 0;
}