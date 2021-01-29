#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///13026_Search_the_Khoj.cpp

int numberOfDiff(string a, string b){
    int cnt  = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])cnt++;
    }
    return cnt;
}

bool check(string a, string b){
    int n = a.size();
    int m = b.size();
    int diff = abs(n - m);
    if(diff >= 2)return false;
    if(a.size() == b.size()){
        int cnt = numberOfDiff(a, b);
        ///cout << cnt << "\n" << a << " " << b << "\n";
        return (cnt <= 1);
    }
    /// _asdf asdf_
    bool flag = false;
    if(a.size() > b.size()){
        string tempb = "0" + b;
        int cnt = numberOfDiff(a, tempb);
        if(cnt <= 1){
            flag |= true;
        }
        tempb = b + "0";
        cnt = numberOfDiff(a, tempb);
        if(cnt <= 1){
            flag |= true;
        }
    }
    if(a.size() < b.size()){
        string tempa = "0" + a;
        int cnt = numberOfDiff(tempa, b);
        if(cnt <= 1){
            flag |= true;
        }
        tempa = a + "0";
        cnt = numberOfDiff(tempa, b);
        if(cnt <= 1){
            flag |= true;
        }
    }
    return flag;
}

int32_t main(){
    __FastIO;
    int tc;
    cin >> tc;
    for(int cs = 1; cs <= tc; cs++){
        int n;
        cin >> n;
        vector<string>number(n);
        for(int i = 0; i < n; i++){
            cin >> number[i];
        }
        string mom;
        cin >> mom;
        vector<string>ans;
        for(string str : number){
            if(check(str, mom)){
                ///cout <<"hhh\n";
                ans.push_back(str);
            }
        }
        cout << "Case " << cs << ":\n";
        for(string str : ans){
            cout << str << "\n";
        } 
    }
    return 0;
}