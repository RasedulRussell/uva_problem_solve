#include<bits/stdc++.h>
using namespace std;

void solution(){
    string num;
    vector<int>v;
    while(getline(cin, num) && num.size() > 0){
        int n = stoi(num);
        v.push_back(n);
    }
    
    int sz = v.size();
    int dp[sz];
    int parent[sz];
    int mx = 1;
    int st = 0;

    for(int i = 0; i < sz; i++){
        dp[i] = 1;
        parent[i] = i;
    }

    for(int i = 0; i < sz; i++){
        for(int j = 0; j < i; j++){
            if(v[i] > v[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j]+1;
                parent[i] = j;
                if(mx < dp[i]){
                    mx = dp[i];
                    st = i;
                }
            }
        }
    }

    cout << "Max hits: " << mx << "\n";
    vector<int>ans;
    while(true){
        if(parent[st] == st){
            ans.push_back(v[st]);
            break;
        }
        ans.push_back(v[st]);
        st = parent[st];
    }
    for(int i = ans.size()-1; i >= 0; i--){
        cout << ans[i] << "\n";
    }
    return;
}

int main(){
    int cs, ok = 0;
    cin >> cs;
    cin.ignore();
    cin.ignore();
    while(cs--){
        if(ok){
            cout << "\n";
        }
        ok = 1;
        solution();
    }
    return 0;
}