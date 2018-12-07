#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;
vector<int>g[30] ;
bool used[30] ;
vector<int>order ;
int cost[30] ;

void allClear()
{
    for( int i = 0; i < 30; i++ ){
        g[i].clear();
        used[i] = false;
    }
    order.clear() ;
}

void dfs( int u )
{
    used[u] = true ;

    for( int i = 0; i < g[u].size(); i++){
        int v = g[u][i] ;
        if( !used[v] ){
            dfs( v );
        }
    }
    order.push_back( u );
}

int main()
{
    int testCase ;
    cin >> testCase;
    getchar() ;
    getchar( ) ;
    for( int t = 1 ; t <= testCase; t++ ){
        if( t != 1 ){
            cout << endl ;
        }
        allClear();
        string line;
        int n = 0 ;
        map<char , int>mp ;
        while( getline( cin , line ) ){
            if( line.size() == 0 ){
                break;
            }
            stringstream st ;
            st << line ;
            int value ;
            string a , other ;
            st >> a ;
            st >> value ;
            st >> other ;
            if( mp[a[0]] == 0 ){
                mp[a[0]] = ++n ;
            }
            for( int i = 0; i < other.size(); i++ ){
                if( mp[other[i]] == 0 ){
                    mp[other[i]] = ++n;
                }
            }

            int u = mp[a[0]] ;
            cost[u] = value ;

            for( int i = 0; i < other.size(); i++  ){
                int v = mp[other[i]] ;
                g[v].push_back( u ) ;
            }
        }

//        for( int i = 1; i <= n; i++ ){
//            cout << i << "| ";
//            for( int j = 0; j < g[i].size(); j++ ){
//                cout << g[i][j] << "    " ;
//            }
//            cout << endl << "--------------------------------" << endl ;
//        }

        dfs( 1 ) ;
        ll update[30] ;
        //memset( update , 100000 , sizeof( update ) );
        for( int i = 1; i <= n; i++ ){
            update[i] = cost[i] ;
        }
        //update[order[order.size()-1]] = cost[order[order.size()-1]] ;
        for(int i = order.size()-1; i >= 0; i--){
            int u = order[i] ;
            for( int j = 0; j < g[u].size(); j++ ){
                int v = g[u][j] ;
                update[v] = max( update[v] , update[u]+cost[v] ) ;
            }
        }
        ll ans = 0 ;
        for( int i = 1; i <= n; i++ ){
            //cout << i << " " << update[i] << endl ;
            ans = max( update[i] , ans );
        }
        cout << ans << endl ;
    }
}
