#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007
#define seed 31
#define nll cout << "\n"
#define nl "\n"
#define MAX 100003
#define dbgv(v) cout << v << nl
#define dbg cout << "dbg\n"


ll arr[1005];
ll A[1005];

int positionFind(int i, int j){

    int pos = i;
    ll mn = INT_MAX;
    ll mx = 0;
    for(int k = i; k <= j; k++){
        if(k != j && A[k] == A[k+1])continue;
        int l = arr[k-1]-arr[i-1];
        int r = arr[j]-arr[k];
        ll dif = abs(l-r);
        if(dif < mn){
            mn = dif; mx = l; pos = k;
        }
        if(l > mx && dif == mn){
            mx = l; pos = k;
        }
    }
    ///cout << i << " " << j << " " << dif << " " << pos << nl;
    return pos;
}

void construction(int i, int j){
    if(j < i){
        return ;
    }

    int pos = positionFind(i, j);
    int data = arr[pos] - arr[pos-1];
    cout << data;
    if(i != j){
        cout << "(";
        construction(i, pos-1);
        if(i != pos && j != pos){
            cout << ",";
        }
        construction(pos+1, j);
        cout << ")";
    }
}

int main(){
    __FastIO;
    int n;
    int tc = 0;
    cin >> tc;
    for(int Case = 1; Case <= tc; Case++){
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> A[i];
        }
        sort(A+1, A+n+1);
        arr[0] = 0;
        for(int i = 1; i <= n; i++){
            arr[i] = arr[i-1] + A[i];
        }
        cout << "Case #" << Case << ": ";
        construction(1, n);
        nll;
    }
}

