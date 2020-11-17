#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define MOD 1000000007
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


int r[8] = {-1,  0, +1, +1, +1,  0, -1, -1};
int c[8] = {-1, -1, -1,  0, +1, +1, +1, 0};

///12720_Algorithm_of_Phil.cpp

int bigMod(int base, int p){
    int ans = 1;
    while(p){
        if(p & 1){
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        p >>= 1;
    }
    return ans;
}

int process(string& input){
    int sz = input.size();
    if(sz <= 1){
        if(input[0] == '0')return 0;
        return 1;
    }
    int left, right;
    if(sz % 2 == 0){
        right = sz / 2;
        left = right - 1;
    }else{
        right = sz / 2;
        left = right;
    }
    string ans = "";
    if(left == right){
        ans.push_back(input[left]);
        right++;
        left--;
    }
    while(true){
        int leftSize = left + 1;
        int rightSize = sz - right;
        int totalSize = (leftSize + rightSize);
        if(totalSize == 1){
            if(left == 0){
                ans.push_back(input[left]);
            }else{
                ans.push_back(input[right]);
            }
            break;
        }
        if(totalSize % 2 == 1){
            if(rightSize > leftSize){
                ans.push_back(input[right]);
                right++;
            }else{
                ans.push_back(input[left]);
                left--;
            }
        }else{
            if(input[left] < input[right]){
                ans.push_back(input[right]);
                right++;
            }else{
                ans.push_back(input[left]);
                left--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    int ansValue = 0;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == '1'){
            ansValue += bigMod(2, i);
            ansValue = ansValue % MOD;
        }
    }
    return ansValue;
}

int32_t main(){
    __FastIO;
    int tc, cs = 1;
    cin >> tc;
    while(tc--){
        string input;
        cin >> input;
        cout << "Case #" << cs++ << ": " << process(input) << "\n";
    }
    return 0;
}