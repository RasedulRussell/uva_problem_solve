#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

/// 1368_DNA_Consensus_String.cpp

int memo[MAX][5];

int32_t main(){
    map<char, int>mp;
    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;
    int cs;
    cin >> cs;
    while(cs--){
        int N, sz;
        cin >> N >> sz;
        vector<string>strings(N);
        for(int i = 0; i < N; i++){
            cin >> strings[i];
        }
        memset(memo, 0, sizeof memo);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < sz; j++){
                memo[j][mp[strings[i][j]]]++;
            }
        }
        string ans = "";
        int dis = 0;
        for(int i = 0; i < sz; i++){
            int x = max(memo[i][0], max(memo[i][1], max(memo[i][2], memo[i][3])));
            if(memo[i][0] == x){
                dis += memo[i][1] + memo[i][2] + memo[i][3];
                ans.push_back('A');
            }else if(x == memo[i][1]){
                ans.push_back('C');
                dis += memo[i][0] + memo[i][2] + memo[i][3];
            }else if(x == memo[i][2]){
                ans.push_back('G');
                dis += memo[i][0] + memo[i][1] + memo[i][3];
            }else{
                ans.push_back('T');
                dis += memo[i][0] + memo[i][1] + memo[i][2];
            }
        }
        cout << ans << "\n" << dis << "\n";
    }
    return 0;
}