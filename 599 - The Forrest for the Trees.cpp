#include<bits/stdc++.h>

using namespace std ;

vector<int>g[30] ;
int visit[30] ;
int nCount = 0;

void allClear()
{
    for( int i = 0 ; i < 30 ; i++ ){
        g[i].clear() ;
        visit[i] = false ;
    }
}

void dfs( int u )
{
    visit[u] = true ;
    nCount++ ;

    for( int i = 0; i < g[u].size(); i++ ){
        if( !visit[g[u][i]] ){
            dfs( g[u][i] ) ;
        }
    }
}

int main()
{
    map<char,int>mp ;

    for( int i = 0 ; i < 26 ; i++ ){
        mp['A'+i] = i ;
    }
    int testCase ;
    cin >> testCase ;

    for( int t = 0 ; t < testCase; t++ ){

        allClear() ;
        int cnt = 0 ;

        while( 1 ){
            string s ; cin >> s ;
            if( s[0] != '(' ){
              break ;
            }
            char a , b ;
            a = s[1] ;
            b = s[3] ;
            g[mp[a]].push_back( mp[b] ) ;
            g[mp[b]].push_back( mp[a] ) ;
        }

        vector<int>v ;
        string point ;
        cin >> point ;

        for( int i = 0; i < point.size(); i++ ){
            if( point[i] >= 'A' && point[i] <= 'Z' ){
                v.push_back( mp[point[i]] ) ;
            }
        }

        int tree = 0 , acorn = 0 ;

        for( int i = 0; i < v.size(); i++ ){
            if( !visit[v[i]] ){
                ///cout << v[i] << endl ;
                nCount = 0 ;
                dfs( v[i] ) ;
                if( nCount > 1 ){
                    tree++ ;
                }
                else{
                    acorn++ ;
                }
            }
        }

        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl ;
    }
}
