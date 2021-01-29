#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///741_Burrows_Wheeler_Decoder.cpp

int32_t main(){
    __FastIO;
    string str;
    int pos;
    int cs = 0;
    while(cin >> str >> pos){
        if(str == "END" && pos == 0)break;
        if(cs){
            cout << "\n";
        }
        cs = 1;
        int n = str.size();
        vector<string>ans(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[j].insert(ans[j].begin(), str[j]);
            }
            sort(ans.begin(), ans.end());
        }
        cout << ans[pos - 1] << "\n";
    }
    return 0;
}