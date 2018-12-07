#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

int main()
{
    int t = 1 ;
    int a , b ;
    while( cin >> a >> b && a && b ){
        ull table[102][102] ;
        set<int>differentnote ;
        int max_note=0 ;

        for( int i = 0 ; i <= 100 ; i++ ){
            for( int j = 0 ; j <= 100 ; j++ ){
                if( i == j ){
                    table[i][j] = 0 ; continue ;
                }
                table[i][j] = 1000000000 ;
            }
        }

        table[a][b] = 1 ;
        differentnote.insert( a ) ;
        differentnote.insert( b ) ;
        max_note = max( max_note , max( a , b ) ) ;
        while( cin >> a >> b && a && b ){
            table[a][b] = 1 ;
            differentnote.insert( a ) ;
            differentnote.insert( b ) ;
            max_note = max( max_note , max( a , b ) ) ;
        }

        for( int k = 1 ; k <= max_note ; k++ ){
            for( int i = 1 ; i <= max_note ; i++ ){
                for( int j = 1 ; j <= max_note ; j++ ){
                    table[i][j] = min( table[i][j] , table[i][k]+table[k][j] ) ;
                }
            }
        }

        ull sum = 0 ;

        for( int i = 1 ; i <= max_note ; i++ ){
            for( int j = 1 ; j <= max_note ; j++ ){
                if( table[i][j] < 1000000000 ){
                    sum+=table[i][j] ;
                }
            }
        }

        int n = differentnote.size() ;
        ull path = n*(n-1) ;

        printf("Case %d: average length between pages = %.3lf clicks\n",t++ , (float)sum/path) ;
    }
}

