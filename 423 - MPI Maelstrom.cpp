#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

int main( )
{
    int n ;

    while( cin >> n ){
        ull dp[n+3][n+3] ;

        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if( i == j ){
                    dp[i][j] = 0 ; continue ;
                }
                dp[i][j] = 1000000000 ;
            }
        }

        for( int i = 2 ; i <= n ; i++ ){
            for( int j = 1 ; j < i ; j++ ){
                string a ;
                cin >> a ;
                if( a[0] != 'x' ){
                    stringstream st ;
                    st << a;
                    ull b ;
                    st >> b ;
                    dp[i][j] = b ;
                    dp[j][i] = b ;
                }
            }
        }

        for( int k = 1 ; k <= n ; k++ ){
            for( int i = 1 ; i <= n ; i++ ){
                for( int j = 1 ; j <= n ; j++ ){
                    dp[i][j] = min( dp[i][j] , dp[i][k]+dp[k][j] ) ;
                }
            }
        }
        ull ans = 0 ;

        for( int i = 2 ; i <= n ; i++ ){
            ans = max( ans , dp[1][i] ) ;
        }

        cout << ans << endl ;
    }
    return 0 ;
}
