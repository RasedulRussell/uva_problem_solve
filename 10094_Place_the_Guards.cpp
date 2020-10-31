///10094_Place_the_Guards.cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n < 4){
            cout << "Impossible\n";
            continue;
        }
        vector<int>ans;
        if(n%6 == 2){
            for(int i = 2; i <= n; i+=2){
                ans.push_back(i);
            }
            ans.push_back(3);
            ans.push_back(1);
            for(int i = 7; i <= n; i+=2){
                ans.push_back(i);
            }
            ans.push_back(5);
        }else if(n % 6 == 3){
            for(int i = 4; i <= n; i+=2){
                ans.push_back(i);
            }
            ans.push_back(2);
            for(int i = 5; i <= n; i+=2){
                ans.push_back(i);
            }
            ans.push_back(1);
            ans.push_back(3);
        }else{
            for(int i = 2; i <= n; i+=2){
                ans.push_back(i);
            }
            for(int i = 1; i <= n; i+=2){
                ans.push_back(i);
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i];
            if(i != n-1){
                cout << " ";
            }else{
                cout << "\n";
            }
        }
    }
    return 0;
}