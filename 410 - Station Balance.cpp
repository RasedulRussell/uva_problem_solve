#include<bits/stdc++.h>

using namespace std ;

int main()
{
    double t = 1 ;
    int c, n ;
    while( cin >> c >> n ){
        vector<int>v(c*2 , 0) ;
        double sum = 0.0 ;
        for( int i = 0 ; i < n ; i++ ){
            cin >> v[i] ;
            sum += v[i] ;
        }
        cout << "Set #" << t++ << endl ;
        double im =0.0 ;
        for( int i = 0 ; i < c;i++ ){
            cout << " " << i << ":" ;
            int m = i ; int o = 2*c - i - 1 ;
            if( v[m]!=0 )cout << " " << v[m] ;
            if( v[o]!=0 )cout << " " << v[o] ;
            cout << endl ;
        }
    }
    return 0 ;
}
