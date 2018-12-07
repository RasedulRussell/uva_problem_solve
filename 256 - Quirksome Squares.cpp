#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;
typedef long long ll ;

int digit( ull n )
{
    if( n == 0 ){
        return 0 ;
    }
    return 1+digit( n/10 ) ;
}

int power( int n )
{
    int ans = 1 ;
    for( int i = 0 ; i < n ; i++ ){
        ans = ans*10 ;
    }
    return ans ;
}

int main( )
{
    vector<ull>result[10] ;
    for( int i = 2 ;  ;  i++ ){
        int d = digit( i*i ) ;
        if( d > 8 ){
           /// cout << i <<endl ;
            break ;
        }
        if( d%2 == 0 ){
            int mod = power( d/2 ) ;
            ull N = i*i ;
            ull n = N%mod ;
            ull nn = N/mod ;
            ull sum = n+nn ;
            if( sum*sum == N ){
                result[d].push_back( N ) ;
                ///cout << N << endl ;
            }
        }
        else{
            int mod = power( d/2 ) ;
            int mod2 = mod*10 ;
            ull N = i*i ;
            int n = N%mod ;
            int nn = N%mod2 ;
            ull sum1 =  n + N/mod ;
            ull sum2 = nn + N/mod2 ;
            if( sum2*sum2 == N ){
                ////for( int i = d+1 ; i <= 8  ; i++ ){
                  ////  if( i%2 == 0 ){
                        result[d+1].push_back( N ) ;
                    ///}
               /// }
            }
        }
    }
    int d ;
    while( cin >> d ){
        for( int i = 0 ; i < d ; i++ ){
            cout << "0" ;
        }
        cout << endl ;
        for( int i = 0 ; i < d-1 ; i++ ){
            cout << "0" ;
        }
        cout << "1" << endl ;
        for( int i = 0 ; i < result[d].size( ) ; i++ ){
            int di = digit( result[d][i] ) ;
            if( di == d ){
                cout << result[d][i] << endl ;
            }
            else{
                for( int i = 0 ; i < abs( d - di ) ; i++ ){
                    cout << "0" ;
                }
                cout << result[d][i] << endl ;
            }
        }
    }
    return 0 ;
}




