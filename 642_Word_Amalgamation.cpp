#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///642_Word_Amalgamation.cpp

bool check(string a, string b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return (a == b);
}

int32_t main(){
    __FastIO;
    vector<string>words;
    string word;
    while(cin >> word){
        if(word == "XXXXXX") break;
        words.push_back(word);
    }
    sort(words.begin(), words.end());
    while(cin >> word){
        if(word == "XXXXXX") break;
        bool flag = true;
        for(string str : words){
            if(check(word, str)){
                flag = false;
                cout << str << "\n";
            }
        }
        if(flag){
            cout << "NOT A VALID WORD\n";
        }
        cout << "******\n";
    }
    return 0;
}