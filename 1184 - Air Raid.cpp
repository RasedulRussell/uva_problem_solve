#include<bits/stdc++.h>

using namespace std ;

vector<int>g[150] ;
bool used[150] ;
vector<int>order;

void dfs( int u )
{
    used[u] = true ;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i] ;
        if( !used[v] ){
            dfs( v );
        }
    }
   // cout << u << endl ;
    order.push_back( u ) ;
}

void Clear()
{
    for( int i = 0; i < 150; i++ ){
        g[i].clear();
        used[i] = false;
    }
    order.clear();
}

bool cheak( vector<int>&temp , int u )
{
    for( int i = 0; i < temp.size(); i++ ){
        if( temp[i] == u && !used[u] ){
            return true;
        }
    }
    return false;
}

int f(int n)
{
    int cnt = 0;
    ///memset( used , false , sizeof( used ) );

    for( int i =0; i <= n; i++ ){
        used[i] = false ;
    }

    for( int i = 0; i < order.size(); i++ ){
        int a = order[i] ;
        if( used[a] == false ){
            cnt++;
            int v = a;
            used[v] = true ;
            for( int j = i+1; j < order.size(); j++ ){
                int u = order[j] ;
                if( cheak( g[v] , u ) ){
                    v = u ;
                    used[v] = true ;
                }
            }
        }
    }
    return cnt ;
}

int main()
{
    int t ;
    cin >> t ;

    for( int Case = 1; Case <= t; Case++ ){

        Clear();

        int n, m;
        cin >> n >> m;
        for( int k = 0; k < m; k++ ){
            int a , b;
            cin >> a >> b;
            g[a].push_back( b );
        }

        for( int i = 1; i <= n; i++ ){
            if( !used[i] ){
                dfs( i );
            }
        }
        reverse( order.begin() , order.end() );
        //cout << endl ;
        cout << f(n) << endl ;
    }
}




