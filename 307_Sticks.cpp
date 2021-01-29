#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 100003
#define MOD  10000019
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///307_Sticks.cpp

int n;
int sticks;
int stickSize;
int valid[110];
int rightValues[110];
vector<int>values;


bool fun(int pos, int needStart, int stickId, int sum){
    if(sum == stickSize){
        if(stickId+1 == sticks)return true;
        if(fun(0, 1, stickId+1, 0)){
            return true;
        }
        return false;
    }
    if(needStart){
        int id;
        for(int i = 0; i < n; i++){
            if(valid[i] == 1){
                id = i;
                break;
            }
        }
        valid[id] = 0;
        if(fun(id+1, 0, stickId, values[id])){
            return true;
        }
        valid[id] = 1;
    }else{
        bool flag = false;
        for(int i = pos; i < n; i++){
           if(valid[i] == 1 && sum+values[i] <= stickSize && sum+rightValues[i] >= stickSize){
               if(i && values[i] == values[i-1] && valid[i-1] == 1){
                   continue;
               }
               valid[i] = 0;
               if(fun(i+1, 0, stickId, sum+values[i])){
                   return true;
               }
               valid[i] = 1;
               if(sum+values[i] == stickSize)return false;
           }
        }
    }
    return false;
}

int32_t main(){
    while(cin >> n && n){
        values.clear();
        int sum = 0;
        int val;
        for(int i = 0; i < n; i++){
            cin >> val;
            sum += val;
            valid[i] = 1;
            values.push_back(val);
        }
       
        sort(values.begin(), values.end(), greater<int>());
        rightValues[n] = 0;
        for(int i = n-1; i >= 0; i--){
            rightValues[i] = rightValues[i+1]+values[i];
        }
        bool flag = false;
        for(int i = values[0]; i < sum; i++){
            if(sum % i == 0){
                stickSize = i;
                sticks = sum / i;
                flag = fun(0, 1, 0, 0);
            }
            if(flag){
                cout << i << "\n";
                break;
            }
        }
        if(!flag){
            cout << sum << "\n";
        }
    }
    return 0;
}