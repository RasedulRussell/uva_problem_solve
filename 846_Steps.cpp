#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///846_Steps.cpp


int32_t main(){
    __FastIO;
    int cs;
    cin >> cs;
    while(cs--){
        int x, y;
        cin >> x >> y;
        int diff = y - x;
        if(diff <= 3){
            cout << diff << "\n";
            continue;
        }
        int target = diff / 2;
        bool flag = false;
        int sum = 0;
        int step = 0;
        for(int i = 1; ; i++){
            if(sum+i == target){
                flag = true;
                step++;
                break;
            }
            if(sum+i > target){
                break;
            }
            sum += i;
            step++;
        }
        if(flag){
            step *= 2;
            if(diff & 1){
                step++;
            }
        }else{
            int need = (target - sum) * 2;
            if(diff & 1)need++;
            int baki = 1;
            if(need > 1+step){
                baki++;
            }
            step = step * 2 + baki;
        }
        cout << step << "\n";
    }
}