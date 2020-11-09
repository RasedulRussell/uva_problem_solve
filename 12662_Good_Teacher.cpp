#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1000005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///12662_Good_Teacher.cpp

int32_t main(){
    int cs;
    int n;
    while(cin >> n){
        vector<string>name(n);
        for(int i  = 0; i < n; i++){
            cin >> name[i];
        }
        int q;
        cin >> q;
        while(q--){
            int pos; cin >> pos;
            pos--;
            if(name[pos] != "?"){
                cout << name[pos] << "\n"; continue;
            }
            int left = pos-1;
            int right = pos+1;
            while(left >= 0 && name[left] == "?"){
                left--;
            }
            while(right < n && name[right] == "?"){
                right++;
            }
            int leftDiff = (left == -1) ? 100000 : (pos - left);
            int rightDiff = (right == n) ? 100000 : (right - pos);
            if(leftDiff == rightDiff){
                ///middle of D and H
                cout << "middle of " << name[left] << " and " << name[right] << "\n";
                continue;
            }
            if(leftDiff < rightDiff){
                for(int j = 0; j < leftDiff; j++){
                    cout << "right of ";
                }
                cout << name[left] << "\n";
                continue;
            }
            for(int j = 0; j < rightDiff; j++){
                cout << "left of ";
            }
            cout << name[right] << "\n";
        }
    }
    return 0;
}