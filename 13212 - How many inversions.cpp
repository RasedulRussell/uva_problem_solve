#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll marge(int lx, int m, int rx, vector<ll>&arr){
    int n1 = m - lx + 1;
    int n2 = rx - m;
    ll L[n1], R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[i+lx];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[j+m+1];
    }

    ll cnt = 0;
    int idx = lx;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[idx++] = L[i++];
        }else{
            cnt += (n1 - i);
            arr[idx++] = R[j++];
        }
    }
    while(i < n1){
        arr[idx++] = L[i++];
    }
    while(j < n2){
        arr[idx++] = R[j++];
    }
    return cnt;
}

ll margeSort(int lx, int rx, vector<ll>&arr){
    ll sum = 0;
    if(lx < rx){
        int m = (lx + rx) / 2;
        sum += margeSort(lx, m, arr);
        sum += margeSort(m+1, rx, arr);
        sum += marge(lx, m, rx, arr);
        return sum;
    }
    return sum;
}

int main(){
    int n;
    while(cin >> n && n){
        vector<ll>arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll res = margeSort(0, n-1, arr);
        cout << res << "\n";
    }
    return 0;
}
