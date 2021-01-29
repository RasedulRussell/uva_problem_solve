#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10419_Sum_up_the_Primes.cpp

vector<int>primes;
bool is[300];
bool dp[124][15][1003];
int path[15];
int N, numberofprime;

void seive(){
    memset(is, true, sizeof is);
    for(int i = 2; i*i < 300; i++){
        if(is[i]){
            for(int j = i*i; j < 300; j += i){
                is[j] = false;
            }
        }
    }
    primes.push_back(2);
    for(int i = 3; i < 300; i+=2){
        if(is[i]){
            primes.push_back(i);
            primes.push_back(i);
        }
    }
    return;
}

bool found(int pos, int cnt, int sum){
    if(cnt == numberofprime){
        if(sum == N)return true;
        return false;
    }
    if(pos >= primes.size() || sum > N)return false;
    if(!dp[pos][cnt][sum]) return false;
    path[cnt] = primes[pos];
    if(found(pos+1, cnt+1, sum+primes[pos])){
        return true;
    }
    if(found(pos+1, cnt, sum)){
        return true;
    }
    return dp[pos][cnt][sum] = false;
}

void solution(){
    memset(dp, true, sizeof dp);
    if(found(0, 0, 0)){
        cout << path[0];
        for(int i = 1; i < numberofprime; i++){
            cout << "+" << path[i];
        }
        cout << "\n";
    }else{
        cout << "No Solution.\n";
    }
    return ;
}

int32_t main(){
    seive();
    sort(primes.begin(), primes.end(), [](int a, int b){
        string aa = to_string(a);
        string bb = to_string(b);
        return aa < bb;
    });
    int cs = 1;
    while(cin >> N >> numberofprime){
        if(N == 0 && numberofprime == 0)break;
        cout << "CASE " << cs++ << ":\n";
        solution();
    }
    return 0;
}