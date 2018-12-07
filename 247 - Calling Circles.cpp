#include<bits/stdc++.h>

using namespace std ;

vector<int> order , component ;
vector<int>g[30] ;
vector<int>gr[30] ;
vector<bool>used( 30 , false ) ;

void dfs1( int u )
{
    used[u] = true ;

    for( int i = 0 ; i < g[u].size( ) ; i++ ){
        if( !used[g[u][i]] ){
            dfs1( g[u][i] ) ;
        }
    }

    order.push_back( u ) ;
}

void dfs2( int u )
{
    used[u] = true ;
    component.push_back( u ) ;

    for( int i = 0 ; i < gr[u].size( ) ; i++ ){
        if( !used[gr[u][i]] ){
            dfs2( gr[u][i] ) ;
        }
    }
}

void clearUsed()
{
    for( int i = 0 ; i < 30 ; i++ ){
        g[i].clear() ;
        gr[i].clear();
    }
}
int main( )
{
    int n , m  , t = 1;
    while( cin >> n >> m && n != 0 && m != 0 ){

        map<string , int>mp1 ;
        map<int , string>mp2 ;
        int cnt = 1 ;

        if( t != 1 ){
            cout << endl ;
        }

        for( int i = 0 ; i < m ; i++ ){

            string str1 , str2 ;
            cin >> str1 >> str2 ;

            if( mp1[str1] == 0 ){
                mp1[str1] = cnt ;
                mp2[cnt] = str1 ; cnt++ ;
            }

            if( mp1[str2] == 0 ){
                mp1[str2] = cnt ;
                mp2[cnt] = str2 ; cnt++ ;
            }

            g[mp1[str1]].push_back( mp1[str2] ) ;
            gr[mp1[str2]].push_back( mp1[str1] ) ;
        }

        cout << "Calling circles for data set " << t++ << ":" << endl ;
        used.assign( 30 , false ) ;

        for( int i = 1 ; i <= n ; i++ ){
            if( !used[i] ){
                dfs1(i) ;
            }
        }

        used.assign( 30 , false ) ;

        for( int i = n-1 ; i >= 0 ; i-- ){
            if( !used[order[i]] ){

                dfs2( order[i] ) ;

                for( int j = 0 ; j < component.size() ; j++ ){
                    cout << mp2[component[j]] ;
                    if( j == component.size()-1 ){
                        cout << endl ;
                    }
                    else{
                        cout << ", " ;
                    }
                }
                component.clear() ;
            }
        }
        clearUsed() ;
        order.clear() ;
        component.clear() ;
    }
}
