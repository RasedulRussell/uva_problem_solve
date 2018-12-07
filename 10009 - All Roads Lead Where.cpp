#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull ;

map<string , int>mp1 ;
map<int , string>mp2 ;
ull fw[30][30] ;
ull parent[30][30] ;

void clearAll(  )
{
    for( int i = 0 ; i < 30 ; i++ ){
        for( int j = 0 ; j < 30 ; j++ ){
            fw[i][j] = ( i==j )?0:10000000 ;
            parent[i][j] = i ;
        }
    }
}

void pathPrint( int i , int j )
{
    if( i != j ){
        pathPrint( i , parent[i][j] ) ;
    }
    cout << mp2[j][0] ;
}

int main()
{
     int test ;
     cin >> test ;
     int t = 1 ;

     while( test-- ){

       if( t != 1 ){
        cout << endl ;
       }
       t = 3 ;

       clearAll( ) ;

        int n , m ;
        cin >> n >> m ;
        int cnt = 1 ;
        for( int i = 0 ; i < n ; i++ ){
            string a , b ;
            cin >> a >> b ;
            if( mp1[a] == 0 ){
                mp1[a] = cnt++ ;
                mp2[cnt-1] = a ;
            }
            if( mp1[b] == 0 ){
                mp1[b] = cnt++ ;
                mp2[cnt-1] = b ;
            }
            fw[mp1[a]][mp1[b]] = 1 ;
            fw[mp1[b]][mp1[a]] = 1 ;
        }

        for( int k = 1 ; k < cnt ; k++ ){
            for( int i = 1 ; i < cnt ; i++ ){
                for( int j = 1 ; j < cnt ; j++ ){
                    if( fw[i][j] > fw[i][k]+fw[k][j] ){
                        fw[i][j] = fw[i][k]+fw[k][j] ;
                        parent[i][j] = parent[k][j] ;
                    }
                }
            }
        }

        for( int i = 0 ; i < m ; i++ ){
            string a , b ; cin >> a >> b ;
            pathPrint( mp1[a] , mp1[b] ) ;
            cout << endl ;
        }

        mp1.clear( ) ;
        mp2.clear( ) ;
     }
}
