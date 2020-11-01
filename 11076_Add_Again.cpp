#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull factorial[13];

void process(){
    factorial[0] = 1;
    for(int i = 1; i < 13; i++){
        factorial[i] = factorial[i-1] * i;
    }
    return;
}

int main(){
    process();
    int n;
    while(cin >> n && n){
        int arr[10];
        int unique = 0;
        memset(arr, 0, sizeof arr);
        set<int>digit;
        for(int i = 0; i < n; i++){
            int val; cin >> val;
            arr[val]++;
            digit.insert(val);
        }
        ull total = factorial[n];
        for(int i = 0 ; i < 10; i++){
            total /= factorial[arr[i]];
        }
        ull one;
        ///cout << total << " " << one << "\n";
        vector<ull>tenPow;
        tenPow.push_back(1);
        for(int i = 0; i < n-1; i++){
            tenPow.push_back(tenPow[i] * 10);
        }
        
        ull ans = 0;
        for(int i : digit){
            if(i == 0) continue;
            ull times = factorial[n-1];
            for(int j = 0; j < 10; j++){
                if(arr[j] == 0) continue;
                int val = arr[j];
                if(j == i)val--;
                times = times / factorial[val];
            }
            for(int j = 0; j < tenPow.size(); j++){
                ans += (tenPow[j]*times*i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
12
9 0 0 0 0 0 0 0 0 0 0 9
*/