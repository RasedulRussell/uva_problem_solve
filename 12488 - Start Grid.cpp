#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int>initialPosition(n);
        vector<int>finalPosition(n);
        for(int i = 0; i < n; i++){
            cin >> initialPosition[i];
        }
        for(int i = 0; i < n; i++){
            cin >> finalPosition[i];
        }
        reverse(initialPosition.begin(), initialPosition.end());
        reverse(finalPosition.begin(), finalPosition.end());
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if( initialPosition[i] != finalPosition[i] ){
                int currentPosition = 0;
                for( int j = 0; j < n; j++ ){
                    if( finalPosition[i] == initialPosition[j]){
                        currentPosition = j;
                        break;
                    }
                }
                while( currentPosition > i ){
                    swap( initialPosition[currentPosition-1], initialPosition[currentPosition] );
                    currentPosition--;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}

