#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 10000
#define MAX 100005
#define MOD 10000000000007
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///941_Permutations.cpp

int frequency[26];
int factorial[21];
int K, N;

void process(){
    factorial[0] = 1;
    for(int i = 1; i < 21; i++){
        factorial[i] = factorial[i-1] * i;
    }
    return;
}

int parmutation(){
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        cnt += frequency[i];
    }
    int ans = factorial[cnt];
    for(int i = 0; i < 26; i++){
        ans /= factorial[frequency[i]];
    }
    return ans;
}

string utilFun(){
    string ans = "";
    while(N){
        bool found = true;
        int left = 0;
        for(int i = 0; i < 26 && found; i++){
            if(frequency[i] == 0) continue;
            frequency[i]--;
            int now = parmutation();
            if(now + left >= K){
                K -= left;
                ans.push_back('a' + i);
                N--;
                found = false;
            }else{
                left += now;
                frequency[i]++;
            }
        }
    }
    return ans;
}

int32_t main(){
    process();
    string str;
    int cs;
    cin >> cs;
    while(cs--){
        cin >> str;
        memset(frequency, 0, sizeof frequency);
        for(char ch : str){
            frequency[ch - 'a']++;
        }
        N = str.size();
        cin >> K;
        K++;
        cout << utilFun() << "\n";
    }
    return 0;
}