#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;

int main( )
{
    int test=7 ;
    cin >> test ;

    for( int t = 1 ; t <= test ; t++ ){

        ull table1[200][200] ;
        ull table2[200][200] ;

        for( int i = 0 ; i < 200 ; i++ ){
            for( int j = 0 ; j < 200 ; j++ ){
                table1[i][j] = (i==j) ? 0 : 10000000 ;
                table2[i][j] = (i==j) ? 0 : 10000000 ;
            }
        }
        map<char , int>mp ;
        int cnt = 1 ;

        int n ;
        cin >> n ;

        for( int i  = 0 ; i < n ; i++ ){
            char a , b ; cin >> a >> b ;
            if( mp[a] == 0 ){
                mp[a] = cnt++ ;
            }
            if( mp[b] == 0 ){
                mp[b] = cnt++ ;
            }

            table1[mp[a]][mp[b]] = 1 ;
            table1[mp[b]][mp[a]] = 1 ;
        }

        bool flag = false ;

        cin >> n ;

        for( int i = 0 ; i < n ; i++ ){
            char a , b ; cin >> a >> b ;
            if( mp[a] == 0  || mp[b] == 0 ){
                flag = true ;
            }
            table2[mp[a]][mp[b]] = 1 ;
            table2[mp[b]][mp[a]] = 1 ;
        }

        if( flag ){
            cout << "NO" << endl ; continue ;
        }

        for( int k = 1 ; k < cnt ; k++ ){
            for( int i = 1 ; i < cnt ; i++ ){
                for( int j = 1 ; j < cnt ; j++ ){
                    ull temp1 = min( table1[i][j] , table1[i][k]+table1[k][j] ) ;
                    ull temp2 = min( table2[i][j] , table2[i][k] + table2[k][j] ) ;
                    ///if( temp1 == temp2 || table1[i][j] != table2[i][j] ){
                        table1[i][j] = temp1 ;
                        table2[i][j] = temp2 ;
                    ///}
                }
            }
        }

        for( int i = 1 ; i < cnt ; i++ ){
            for( int j = 1 ; j < cnt ; j++ ){
                if( (table1[i][j] < 10000000 && table2[i][j] < 10000000)||( table1[i][j] == table2[i][j] )  ){
                    continue ;
                }
                flag = true ;
            }
            if( flag )break ;
        }

        if( flag ){
            cout << "NO" << endl ;
        }
        else{
            cout << "YES" << endl ;
        }
        if( t != test ){
            cout << endl ;
        }
    }
}
