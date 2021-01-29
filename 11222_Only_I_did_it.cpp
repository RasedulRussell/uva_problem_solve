#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11222_Only_I_did_it.cpp

int memo[4][10004];

int32_t main(){
    __FastIO;
    int tc;
    cin >> tc;
    for(int cs = 1; cs <= tc; cs++){
        memset(memo, 0, sizeof memo);
        for(int i = 1; i <= 3; i++){
            int s; cin >> s;
            for(int j = 0; j < s; j++){
                int problem;
                cin >> problem;
                memo[i][problem] = 1;
            }
        }
        vector<int>aunique, bunique, cunique;
        for(int i = 0; i < 10001; i++){
            if(memo[1][i] == 1 && memo[2][i] == 0 && memo[3][i] == 0){
                aunique.push_back(i);
            }
            if(memo[2][i] == 1 && memo[1][i] == 0 && memo[3][i] == 0){
                bunique.push_back(i);
            }
            if(memo[2][i] == 0 && memo[1][i] == 0 && memo[3][i] == 1){
                cunique.push_back(i);
            }
        }
        int mx = max(aunique.size(), max(bunique.size(), cunique.size()));
        cout << "Case #" << cs << ":\n";
        if(aunique.size() == mx){
            cout << "1 " << mx;
            for(int pro : aunique){
                cout << " " << pro;
            }
            cout << "\n";
        }
        if(bunique.size() == mx){
            cout << "2 " << mx;
            for(int pro : bunique){
                cout << " " << pro;
            }
            cout << "\n";
        }
        if(cunique.size() == mx){
            cout << "3 " << mx;
            for(int pro : cunique){
                cout << " " << pro;
            }
            cout << "\n";
        }
    }
    return 0;
}