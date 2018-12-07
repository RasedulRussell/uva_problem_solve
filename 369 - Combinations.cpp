#include<bits/stdc++.h>

using namespace std ;

unsigned long long BC( int n , int k )
{
    if( k > ( n-k ) ){
        k = n - k ;
    }
    unsigned long long bCofficent = 1 ;
    for( int i = 0 ; i < k ; i++ )
    {
        bCofficent *= ( n-i ) ;
        bCofficent /= i+1 ;
    }
    return bCofficent ;
}

int main( )
{
    int n , k ;
    while( cin >> n >> k )
    {
        if( n == 0 && k == 0 )
            return 0 ;
        /// 100 things taken 6 at a time is 1192052400 exactly.
        cout << n << " things taken " << k << " at a time is " << BC( n , k ) << " exactly." << endl ;
    }
    return 0 ;
}
