#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n , m , q ;
    int t = 1 ;

    while( cin >> n >> m >> q && n && m && q ){
        int fw[n+2][n+2] ;
        if( t != 1 ){
            cout << endl ;
        }
        for( int i = 0 ; i <=  n ; i++ ){
            for( int j = 0 ; j <= n ; j++ ){
                if( i == j ){
                    fw[i][j] = 0 ; continue ;
                }
                fw[i][j] = 1000000 ;
            }
        }
        int a , b , c ;
        for( int i = 0 ; i < m ; i++ ){
            cin >> a >> b >> c ;
            fw[a][b] = c ;
            fw[b][a] = c ;
        }

        for( int k = 1 ; k <= n ; k++ ){
            for( int i = 1 ; i <= n ; i++ ){
                for( int j = 1 ; j <= n ; j++ ){
                    fw[i][j] = min( fw[i][j] , max( fw[i][k] , fw[k][j] ) ) ;
                }
            }
        }
        cout << "Case #" << t++ << endl ;
        for( int i = 0 ; i < q ; i++ ){
            cin >> a >> b ;
            if( fw[a][b] == 1000000 ){
                cout << "no path" << endl ;
            }
            else{
                cout << fw[a][b] << endl ;
            }
        }

    }
    return 0 ;
}
