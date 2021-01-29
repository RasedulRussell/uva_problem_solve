#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///703 Triple Ties: The Organizer’s Nightmare.cpp

vector<int> max(vector<int>a, vector<int>b){
    if(a[0] > b[0])return a;
    return b;
}

vector<int> fun(vector<int>a){
    vector<int> b = {a[2], a[0], a[1]};
    vector<int> c = {a[1], a[2], a[0]};
    return max(a, max(b, c));
}

int32_t main(){
    int n;
    while(cin >> n){
        int match[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> match[i][j];
            }
        }
        set<vector<int>>ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                for(int k = 0; k < n; k++){
                    if(j == k || i == k) continue;
                    int cnt = match[i][j] + match[j][i] + match[j][k] + match[k][j] + match[k][i] + match[i][k];
                    vector<int> temp = {i+1, j+1, k+1};
                    sort(temp.begin(), temp.end());
                    if(cnt == 0 && ans.find(temp) == ans.end()){
                        ans.insert(temp);
                    }
                    if((i < j && j < k) || (i > j && j > k)){
                        if(match[i][j] == 1 && match[j][k] == 1 && match[k][i] == 1){
                            ans.insert({i+1, j+1, k+1});
                        }
                    }
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto v : ans){
            cout << v[0] << " " << v[1] << " " << v[2] << "\n";
        }
    }
    return 0;
}