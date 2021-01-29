#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 2000005
#define MOD 1000000007
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"


///11040 Add bricks in the wall.cpp

int32_t main(){
    __FastIO;
    int cs;
    cin >> cs;
    while(cs--){
        vector<int>arr[6];
        for(int i = 1; i <= 5; i++){
            for(int j = 0; j < i; j++){
                int val;
                cin >> val;
                arr[i].push_back(val);
            }
        }
        
        vector<vector<int>>ans;
        ans.push_back(arr[1]);

        for(int i = 2; i <= 5; i++){
            
            int z = (arr[i-1][0] - (arr[i][0] + arr[i][1])) / 2;
            int x = z + arr[i][0];
            
            vector<int>temp;
            temp.push_back(x);
            int sz = ans.size();

            for(int j = 0; j < ans[sz-1].size(); j++){
                int val = ans[sz-1][j] - x;
                temp.push_back(val);
                x = val;
            }
            ans.push_back(temp);
            temp.clear();
            sz = ans.size() - 1;
            x = arr[i][0];
            temp.push_back(x);
            for(int j = 0; j < ans[sz].size(); j++){
                int val = ans[sz][j] - x;
                temp.push_back(val);
                x = val;
            }
            ans.push_back(temp);
        }
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i][0];
            for(int j = 1; j < ans[i].size(); j++){
                cout << " " << ans[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}