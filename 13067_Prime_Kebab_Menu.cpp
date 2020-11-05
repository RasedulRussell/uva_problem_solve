#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 10000
#define MAX 10000005
#define MOD 10000000000007
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///13067_Prime_Kebab_Menu.cpp

vector<int>prime;
bool is_prime[MAX];

void seive(){
    memset(is_prime, true, sizeof is_prime);
    for(int i = 2; i*i < MAX; i++){
        if(is_prime[i]){
            for(int j = i*i; j < MAX; j+=i){
                is_prime[j] = false;
            }
        }
    }
    for(int i = 2; i < MAX; i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }
    return;
}

int32_t main(){
    seive();
    int size = prime.size();
    int n;
    while(cin >> n && n != 1){
        int ans = 0;
        for(int i = 0; i < size && prime[i]*prime[i] <= n; i++){
            while(n > 1 && n % prime[i] == 0){
                ans++;
                n = n / prime[i];
            }
        }
        if(n > 1)ans++;
        cout << ans << "\n";
    }
    return 0;
}
