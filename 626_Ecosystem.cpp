#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///626_Ecosystem.cpp

vector<int> min(vector<int>a, vector<int>b){
    for(int i = 0; i < 3; i++){
        if(a[i] == b[i]) continue;
        if(a[i] < b[i])return a;
        return b;
    }
    return b;
}

vector<int> fun(vector<int>a){
    vector<int>b = {a[2], a[0], a[1]};
    vector<int>c = {a[1], a[2], a[0]};
    return min(a, min(b,c));
}

int32_t main(){
    int n;
    while(cin >> n){
        int grid[n][n];
        vector<int>graph[100];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
                if(grid[i][j]){
                    graph[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j : graph[i]){
                if(i == j) continue;
                for(int k : graph[j]){
                    if(j == k ) continue;
                    if(k != i && grid[k][i] == 1){
                        if((i+1 > j+1 && j+1 > k+1) || (i+1 < j+1 && j+1 < k+1)){
                            ans++;
                            cout << i+1 << " " << j+1 << " " << k+1 << "\n";
                        }
                    }
                }
            }
        }
        cout << "total:" << ans << "\n\n";
    }
    return 0;
}