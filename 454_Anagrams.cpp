#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///454_Anagrams.cpp

string process(string a){
    string temp(a);
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    sort(temp.begin(), temp.end());
    return temp;
}

int32_t main(){
    __FastIO;
    int cs;
    cin >> cs;
    cin.ignore();
    cin.ignore();
    for(int tc = 0; tc < cs; tc++){
        if(tc != 0){
            cout << "\n";
        }
        string line;
        vector<string>input;
        while(getline(cin, line)){
            if(line.size() == 0)break;
            input.push_back(line);
        }
        sort(input.begin(), input.end());
        for(int i = 0; i < input.size(); i++){
            for(int j = i+1; j < input.size(); j++){
                if(process(input[i]) == process(input[j])){
                    cout << input[i] << " = " << input[j] << "\n";
                }
            }
        }
    }
    return 0;
}