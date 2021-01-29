#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///1610_Party_Games.cpp

string fun(string a, string b){
    int n = min(a.size(), b.size());
    int i = 0;
    string ans = "";
    for(i = 0; i < n; i++){
        if(a[i] == b[i]){
            ans.push_back(a[i]);
            continue;
        }
        break;
    }
    if(i == b.size() || i == a.size() - 1 || i == a.size())return a;
    ///ABCEF
    ///ABD
    for(int j = 0; j < 1001; j++){
        for(char ch = 'A'; ch <= 'Z'; ch++){
            string temp = ans + ch;
            if(a <= temp && b > temp){
                return temp;
            }
        }
        ans.push_back(a[i++]);
        if(i == a.size() - 1 || i == a.size())return a;
    }
    return ans;
}

int32_t main(){
    __FastIO;
    int n;
    while(cin >> n && n){
        vector<string>names;
        string name;
        for(int i = 0; i < n; i++){
            cin >> name;
            names.push_back(name);
        }
        sort(names.begin(), names.end());
        n = n / 2;
        string a = names[n-1];
        string b = names[n];
        string ans = fun(a, b);
        cout << ans << "\n";
    }
    return 0;
}