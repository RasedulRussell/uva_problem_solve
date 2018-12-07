#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

int p[11][11] ;
vector<int>path ;

void printPath( int i , int j )
{
    if( i != j ){
        printPath( i , p[i][j] ) ;
    }
    path.push_back( j ) ;
}

int main( )
{
    int n , t = 1;
    while( cin >> n && n != 0 ){
        ull dp[n+3][n+3] ;
        path.clear( ) ;

        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if( i == j ){
                    dp[i][j] = 0 ;continue ;
                }
                dp[i][j] = 1000000000 ;
            }
        }

        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                p[i][j] = i ;
            }
        }

        for( int i = 1 ; i <= n ; i++ ){
            int a ;
            cin >> a ;

            for( int j = 0 ; j < a ; j++ ){
                int b , c ; cin >> b >> c ;
                dp[i][b] = c ;
                ///dp[b][i] = c ;
            }
        }

        int s , d ; cin >> s >> d ;

        for( int k = 1 ; k <= n ; k++ ){
            for( int i = 1 ; i <= n ; i++ ){
                for( int j = 1 ; j <= n ; j++ ){
                    if( dp[i][k]+dp[k][j] < dp[i][j] ){
                        dp[i][j] = dp[i][k]+dp[k][j] ;
                        p[i][j] = p[k][j] ;
                    }
                }
            }
        }

        printPath( s , d ) ;

        cout << "Case " << t++ << ": Path = " ;
        for( int i = 0 ; i < path.size() ; i++ ){
            cout << path[i] ;
            if( i != path.size() -1 ){
                cout << " " ;
            }
            else{
                cout << "; " ;
            }
        }

        cout << dp[s][d] << " second delay" << endl ;

    }
    return 0 ;
}
