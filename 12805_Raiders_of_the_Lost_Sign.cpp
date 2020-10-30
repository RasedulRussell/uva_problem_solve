#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define INF 10000
#define MAX 100005
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int smallPrimeFactor[MAX];
int ans[MAX];

void seive(){
    for(int i = 0; i < MAX; i++){
        smallPrimeFactor[i] = i;
    }

    for(int i = 2; i < MAX; i++){
        if(smallPrimeFactor[i] == i){
            for(int j = i*2; j < MAX; j+=i){
                smallPrimeFactor[j] = min(smallPrimeFactor[j], i);
            }
        }
    }
    return;
}

void process(){
    seive();
    ans[2] = 1;
    for(int i = 3; i < MAX; i++){
        int n = i;
        if(smallPrimeFactor[n] == n){
            if((n+1) % 4 == 0){
                ans[n] = 1;
            }else{
                ans[n] = -1;
            }
        }else{
            int tans = 1;
            while(n > 1){
                int pf = smallPrimeFactor[n];
                tans = tans*ans[pf];
                n = n / pf;
            }
            ans[i] = tans;
        }
    }
    return;
}

int main(){
    ///__FastIO;
    process();
    int cs;
    cin >> cs;
    while(cs--){
        int n;
        cin >> n;
        if(ans[n] == 1){
            cout << "+\n";
        }else{
            cout << "-\n";
        }
    }
    return 0;
}

/*
input
6
2
13
45
87
88
100000
output
+
-
-
-
+
-
*/