#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///735 Dart_a_Mania.cpp

int fun(vector<int>a){
    int ans = 6;
    sort(a.begin(), a.end());
    if(a[0] == a[1] && a[1] == a[2]){
        return 1;
    }
    if(a[0] == a[1] || a[1] == a[2]){
        return 3;
    }
    return 6;
}

int score[65];

int32_t main(){
    for(int i = 0; i <= 20; i++){
        score[i] = i;
        score[2*i] = 2*i;
        score[3*i] = 3*i;
    }
    score[61] = 50;

    int n;
    while(cin >> n && n > 0){
        int combination = 0, permutation = 0;
        set<vector<int>>check;
        for(int i = 0; i < 62; i++){
            if(score[i] == 0 && i > 0) continue;
            for(int j = 0; j < 62; j++){
                if(score[j] == 0 && j > 0)continue;
                for(int k = 0; k < 62; k++){
                    if(score[k] == 0 && k > 0) continue;
                    int val = score[i] + score[j] + score[k];
                    if(val == n){
                        vector<int>v = {score[i], score[j], score[k]};
                        sort(v.begin(), v.end());
                        if(check.find(v) == check.end()){
                            combination++;
                            check.insert(v);
                        }
                        permutation++;
                    }
                }
            }
        }
        if(combination == 0){
            cout << "THE SCORE OF "<< n << " CANNOT BE MADE WITH THREE DARTS.\n";
        }else{
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combination << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permutation << ".\n";
        }
        cout << "**********************************************************************\n";
    }
    cout << "END OF OUTPUT\n";
    return 0;
}