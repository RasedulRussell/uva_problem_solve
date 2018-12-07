#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;


int main()
{
    int t = 1 ;
    int first ;
    while(cin >> first){
        ull fw[21][21] ;

        for( int i = 1 ; i <= 20 ; i++ ){
            for( int j = 1 ; j <= 20 ; j++ ){
                fw[i][j] = (i==j)?0:10000000 ;
            }
        }

        for( int i = 0 ; i < first ; i++ ){
            int a ; cin >> a ;
            fw[1][a] = 1 ; fw[a][1] = 1 ;
        }

        for( int i = 2 ; i <= 19 ; i++ ){
            int n ; cin >> n ;
            for( int j = 0 ; j < n ; j++ ){
                int a ; cin >> a ;
                fw[i][a] = 1; fw[a][i] = 1 ;
            }
        }

        for( int k = 1 ; k <= 20 ; k++ ){
            for( int i = 1 ; i <= 20 ; i++ ){
                for( int j = 1 ; j <= 20 ; j++ ){
                    fw[i][j] = min( fw[i][j] , fw[i][k]+fw[k][j] ) ;
                }
            }
        }

        int n ; cin >> n ;
        cout << "Test Set #" << t++ << endl ;
        for( int i = 0 ; i < n ; i++ ){
            int a , b ; cin >> a >> b ;
            if( a <= 9 ){
                cout << " " << a << " to " ;
            }
            else{
                cout << a << " to " ;
            }
            if( b <= 9 ){
                cout << " " << b << ": " << fw[a][b] << endl ;
            }
            else{
                cout << b << ": " << fw[a][b] << endl ;
            }
        }
        cout << endl ;
    }
}
