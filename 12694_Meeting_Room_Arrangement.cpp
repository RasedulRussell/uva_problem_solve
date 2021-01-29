#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12694_Meeting_Room_Arrangement.cpp


int32_t main(){
    __FastIO;
    int n;
    cin >> n;
    while(n--){
        int s, f;
        vector<pair<int,int>>events;
        while(cin >> s >> f){
            if(s == 0 && f == 0)break;
            events.push_back({s,f});
        }
        sort(events.begin(), events.end(), [](pair<int,int>&a, pair<int,int>&b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        int ans = 0;
        int left = -1;
        for(int i = 0; i < events.size(); i++){
            if(left <= events[i].first){
                ans++;
                left = events[i].second;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}