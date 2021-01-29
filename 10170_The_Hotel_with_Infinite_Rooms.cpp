#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 10005
#define INF 100000000
#define EPS 1e-9
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10170_The_Hotel_with_Infinite_Rooms.cpp

int32_t main(){
    __FastIO;
    int s, d;
    while(cin >> s >> d){
        int ans = 0;
        int lo = 0, hi = 1000000000;
        while(hi >= lo){
            int mid = (lo + hi) / 2;
            int val = (mid * (mid + 1)) / 2;
            val = val + (s * (mid + 1));
            if(val >= d){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid+1;
            }
        }
        cout << (s+ans) << "\n";
    }
    return 0;
}