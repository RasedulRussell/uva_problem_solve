#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define INF 10000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
    __FastIO;
    int times;
    cin >> times;
    for(int cs = 1; cs <= times; cs++){
        int n;
        cin >> n;
        char grid[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '.'){
                    map<char, int>mp;
                    if(j-1 >= 0){
                        mp[grid[i][j-1]]++;
                    }
                    if(j+1 < n){
                        mp[grid[i][j+1]]++;
                    }
                    if(i-1 >= 0){
                        mp[grid[i-1][j]]++;
                    }
                    if(i+1 < n){
                        mp[grid[i+1][j]]++;
                    }
                    for(char ch = 'A'; ch <= 'Z'; ch++){
                        if(mp[ch] == 0){
                            grid[i][j] = ch;
                            break;
                        }
                    }
                }
            }
        }
        cout << "Case " << cs << ":\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}