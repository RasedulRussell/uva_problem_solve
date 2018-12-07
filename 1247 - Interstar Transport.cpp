#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

map<char , int>mp1 ;
map<int , char>mp2 ;
ull fw[27][27] ;
ull parent[27][27] ;
vector<int>path ;

void clearAll(  )
{
    for( int i = 0 ; i < 27 ; i++ ){
        for( int j = 0 ; j < 27 ; j++ ){
            fw[i][j] = ( i == j ) ? 0 : 1000000000 ;
            parent[i][j] = i ;
        }
    }
    mp1.clear();
    mp2.clear() ;
}

void pathPrint( int i , int j )
{
    if( i != j ){
        pathPrint( i , parent[i][j] ) ;
    }
    path.push_back( j ) ;
}

int main()
{
    int n , m ;

    while( cin >> n >> m ){
        int cnt = 1 ;
        clearAll( ) ;
        for( int i = 0 ; i < m ; i++ ){
            char a , b ;
            int cost;
            cin >> a >> b >> cost ;

            if( mp1[a] == 0 ){
                mp1[a] = cnt ;
                mp2[cnt] = a ;
                cnt++ ;
            }
            if( mp1[b] == 0 ){
                mp1[b] = cnt ;
                mp2[cnt] = b ;
                cnt++ ;
            }
            fw[mp1[a]][mp1[b]] = cost ;
            fw[mp1[b]][mp1[a]] = cost ;
        }

        for( int k = 1 ; k <= n ; k++ ){
            for( int i = 1 ; i <= n ; i++ ){
                for( int j = 1 ; j <= n ; j++ ){
                    if( fw[i][j] > fw[i][k]+fw[k][j] ){
                        fw[i][j] = fw[i][k]+fw[k][j] ;
                        parent[i][j] = parent[k][j] ;
                    }
                }
            }
        }

        cin >> n ;

        for( int i = 0 ; i < n ; i++ ){
            char  a , b ; cin >> a >> b ;
            pathPrint( mp1[a] , mp1[b] ) ;
            for( int i = 0 ; i < path.size() ; i++ ){
                cout << mp2[path[i]] ;
                if( i == path.size() - 1 ){
                    cout << endl ;
                }
                else{
                    cout << " " ;
                }
            }
            path.clear();
        }

    }
}

