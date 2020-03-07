#include<bits/stdc++.h>

using namespace std;

int main(){
    int times;
    cin >> times;
    for(int Case = 1; Case <= times; Case++){
        int n, k;
        string name;
        cin >> n >> k >> name;
        int cnt = 0;
        for( int i = 0; i < n; i++ ){
            char current = name[i];
            bool flag = false;
            for( int j = max( 0, i-k ); j < i; j++ ){
                if(name[j] == current){
                    flag = true;
                    break;
                }
            }
            if(flag)cnt++;
        }
        cout << "Case " << Case << ": " << cnt << "\n";
    }
}

