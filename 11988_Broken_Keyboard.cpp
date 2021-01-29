#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 105
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     pb push_back
#define     EPS 1e-9

///11988_Broken_Keyboard.cpp

int32_t main(){
    string line;
    while(cin  >> line){
        list<char>ans;
        auto it = ans.begin();
        for(char ch : line){
            if(ch == '['){
                it = ans.begin();
                continue;
            }
            if(ch == ']'){
                it = ans.end(); continue;
            }
            ans.insert(it, ch);
        }
        for(it = ans.begin(); it != ans.end(); ++it){
            cout << *it;
        }
        cout << "\n";
    }
    return 0;
}