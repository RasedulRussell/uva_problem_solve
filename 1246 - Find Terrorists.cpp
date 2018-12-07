#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int st ;
    cin >> st ;
    long long time = 0 ;
    for( int i = 0 ; i < st ; i++ ){
        int n ;
        cin >> n ;
        vector<int>v(n) ;
        for( int j = 0 ; j < n ; j++ ){
            cin >> v[j] ;
        }
        sort( v.begin() , v.end() ) ;
        int mid = v[v.size()/2] ;
        ///cout << mid << endl ;
        for( int j = 0 ; j < v.size() ; j++ ){
            time += abs( mid - v[j] ) ;
        }
    }
    cout << time << endl ;
    return 0;
}
