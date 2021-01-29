#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10264_The_Most_Potent_Corner.cpp

int32_t main(){
    __FastIO;
    int dimension;
    while(cin >> dimension){
        vector<int>weight;
        for(int i = 0; i < (1 << dimension); i++){
            int val; cin >> val;
            weight.push_back(val);
        }
        vector<int>potency;
        for(int i = 0; i < (1<<dimension); i++){
            int sum = 0;
            for(int j = 0; j < (1 << dimension); j++){
                int val  = (i ^ j);
                if(__builtin_popcount(val) == 1){
                    sum += weight[j];
                }
            }
            potency.push_back(sum);
        }
        int ans = INT_MIN;
        for(int i = 0; i < (1 << dimension); i++){
            vector<int>ok;
            for(int j = 0; j < (1 << dimension); j++){
                int val = ( i ^ j );
                if(__builtin_popcount(val) == 1){
                    ans = max(ans, potency[i]+potency[j]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}