#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11093_Just_Finish_it_up.cpp

int32_t main(){
    __FastIO;
    int cs, tc = 1;
    cin >> cs;
    while(cs--){
        int n;
        cin >> n;
        int p[n], q[n];
        for(int i = 0; i < n; i++)cin >> p[i];
        for(int i = 0; i < n; i++)cin >> q[i];
        int sum = 0;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += p[i] - q[i];
            mn = min(mn, sum);
        }
        int index = 0;
        while(mn < 0 && index < n){
            mn -= (p[index] - q[index++]);
        }
        cout << "Case " << tc++ << ": ";
        if(index == n || sum < 0){
            cout << "Not possible\n";
        }else{
            cout << "Possible from station " << index+1 << "\n";
        }
    }
    return 0;
}