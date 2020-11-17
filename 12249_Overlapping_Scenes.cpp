#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define MOD 1000000007
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"

int r[8] = {-1,  0, +1, +1, +1,  0, -1, -1};
int c[8] = {-1, -1, -1,  0, +1, +1, +1, 0};

///12249_Overlapping_Scenes.cpp

int compress(string a, string b){
    string input = a + "#" + b;
    int sz = input.size();
    int pi[sz];
    pi[0] = 0;
    ///cout << input << "\n";
    for(int i = 1; i < sz; i++){
        int j = pi[i-1];
        while(j > 0 && input[i] != input[j]){
            j = pi[j-1];
        }
        if(input[i] == input[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi[sz-1];
}

int32_t main(){
    __FastIO;
    int tc, cs = 1;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<string>str;
        vector<int>all;
        for(int i = 0; i < n; i++){
            string temp;
            cin >> temp;
            all.push_back(i);
            str.push_back(temp);
        }
        int ans = INT_MAX;
        do{
            string temp = str[all[0]];
            for(int i = 1; i < all.size(); i++){
                int cnt = compress(str[all[i]], temp);
                for(int j = cnt; j < str[all[i]].size(); j++){
                    temp.push_back(str[all[i]][j]);
                }
            }
            ans = min(ans, (int)temp.size());
        }while(next_permutation(all.begin(), all.end()));

        cout << "Case " << cs++ << ": " << ans << "\n";
    }
    return 0;
}