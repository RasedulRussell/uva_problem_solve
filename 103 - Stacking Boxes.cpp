#include<bits/stdc++.h>

using namespace std ;

vector<int>g[50] ;
bool visit[50] ;
vector<int>order ;
int parent[50] ;
int max_jay[50] ;
typedef long long ll ;

void allClear()
{
    order.clear() ;
    for( int i = 0 ; i < 50 ; i++ ){
        g[i].clear() ;
        max_jay[i] = 1 ;
        visit[i] = false ;
        parent[i] = i ;
    }
}

void dfs( int u )
{
    visit[u] = true ;

    for( int i = 0 ; i < g[u].size() ; i++ ){
        if( !visit[g[u][i]] ){
            dfs( g[u][i] ) ;
        }
    }
    order.push_back( u ) ;
}

bool compare( vector<int>&v1 , vector<int>&v2 )
{
    for( int i = 0 ; i < v1.size() ; i++ ){
        if( v1[i] >= v2[i] ){
            return false ;
        }
    }
    return true ;
}

vector<int>result ;

void dfs1( int u )
{
    visit[u] = true ;
    for( int i = 0 ; i < g[u].size() ; i++ ){
        int v = g[u][i] ;
        max_jay[v] = max( max_jay[v] , max_jay[u]+1 ) ;
        if( !visit[v] ){
            dfs1( v ) ;
        }
    }
}

int main()
{
    int n , m ;
    while( cin >> n >> m ){

        allClear() ;
        vector<vector<int>>v ;

        for( int i = 0 ; i < n ; i++ ){
            vector<int>temp ;
            for(int j = 0 ; j < m ; j++){
                int a ; cin >> a ;
                temp.push_back( a ) ;
            }
            sort( temp.begin() , temp.end() ) ;
            v.push_back( temp ) ;
            temp.clear() ;
        }

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( i == j ){
                    continue ;
                }
                bool flag = compare( v[i] , v[j] ) ;
                if( flag ){
                    g[j+1].push_back( i+1 ) ;
                }
            }
        }

        for( int i = 1 ; i <= n ; i++ ){
            if( !visit[i] ){
                ///cout << "hello" << endl ;
                dfs( i ) ;
            }
        }

        memset(visit , false , sizeof(visit)) ;

        for( int i = order.size()-1 ; i >= 0 ; i-- ){
            int u = order[i] ;
            for( int j = 0; j < g[u].size(); j++ ){
                int v = g[u][j] ;
               if( max_jay[v] < max_jay[u]+1 ){
                 max_jay[v] = max_jay[u]+1 ;
                 parent[v] = u ;
               }
            }
        }
        int huha = 0 ;
        int pp = 0 ;

        for( int i = 1 ; i <= n ; i++ ){
            if( max_jay[i] > huha ){
                huha = max_jay[i] ;
                pp = i ;
            }
        }
        cout << huha << endl ;
        while( parent[pp] != pp ){
            cout << pp << " " ;
            pp = parent[pp] ;
        }
        cout << pp << endl ;
    }
}
