#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///850_Crypt_Kicker_II.cpp
///the quick brown fox jumps over the lazy dog

vector<int>keyValue = {3, 5, 5, 3, 5, 4, 3, 4, 3};
vector<string> key = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

pair<unordered_map<char, char>, bool> check(string line){
    vector<string>arr;
    stringstream ss(line);
    while(ss >> line){
        if(line.size() > 0){
            arr.push_back(line);
        }
    }
    unordered_map<char, char>ump;
    if(arr.size() != keyValue.size())return {ump, false};
    for(int i = 0; i < keyValue.size(); i++){
        if(keyValue[i] != arr[i].size())return {ump, false};
    }
    for(int i = 0; i < key.size(); i++){
        string a = arr[i];
        string b = key[i];
        for(int j = 0; j < keyValue[i]; j++){
            char cha = a[j];
            char chb = b[j];
            if(ump.count(cha) == 0){
                ump[cha] = chb;
            }else{
                if(ump[cha] != chb)return {ump, false};
            }
        }
    }
    if(ump.size() == 26)return {ump, true};
    return {ump, false};
}

int32_t main(){
    __FastIO;
    int cs;
    int tc = 1;
    cin >> cs;
    cin.ignore();
    cin.ignore();
    while(cs--){
        if(tc != 1){
            cout << "\n";
        }
        tc = 2;
        string line;
        vector<string>lines;
        while(getline(cin, line)){
            if(line.size() == 0)break;
            lines.push_back(line);
        }
        unordered_map<char, char>ump;
        bool flag = false;
        for(int i = 0; i < lines.size(); i++){
            pair<unordered_map<char, char>, bool> temp = check(lines[i]);
            if(temp.second == true){
                flag = true;
                ump = temp.first;
                break;
            }
        }
        if(flag){
            for(string str : lines){
                for(char ch : str){
                    if(ch >= 'a' && ch <= 'z'){
                        cout << ump[ch];
                    }else{
                        cout << ch;
                    }
                }
                cout << "\n";
            }
        }else{
            cout << "No solution.\n";
        }
    }
    return 0;
}