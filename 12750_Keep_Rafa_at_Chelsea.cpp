#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12750_Keep_Rafa_at_Chelsea.cpp


int32_t main(){
    int cs;
    cin >> cs;
    for(int Case = 1; Case <= cs; Case++){
        int n;
        cin >> n;
        vector<char>chars;
        for(int i = 0; i < n; i++){
            char ch;
            cin >> ch;
            chars.push_back(ch);
        }
        bool flag = true;
        int ans = 3;
        for(int i = 2; i < n; i++){
            if(chars[i-1] == 'W' || chars[i-2] == 'W' || chars[i] == 'W'){
                continue;
            }
            ans = i+1;
            flag = false;
            break;
        }
        if(!flag){
            cout << "Case " << Case << ": " << ans << "\n";
        }else{
            cout << "Case " << Case << ": Yay! Mighty Rafa persists!\n";
        }
    }
    return 0;
}