#include<bits/stdc++.h>

using namespace std ;
#define MAX 1005

vector<int>g[MAX] ;
vector<pair<int,int>>critical_link ;
bool used[MAX] ;
int tin[MAX] ;
int fup[MAX] ;
int timer , node , edge ;

bool cmp( pair<int ,int>a , pair<int ,int>b )
{
    if( a.first == b.first ){
        return ( a.second < b.second ) ;
    }
    return ( a.first < b.first ) ;
}

void dfs( int v , int p = -1 )
{
    used[v] = true ;
    tin[v] = fup[v] = ++timer ;

    for( int i = 0 ; i < g[v].size() ; i++ ){
        int to = g[v][i] ;

        if( to == p )continue ;

        if( used[to] ){
            fup[v] = min( fup[v] , tin[to] ) ;
        }
        else{
            dfs( to , v ) ;
            fup[v] = min( fup[v] , fup[to] ) ;
            if( fup[to] > tin[v] ){
                if( v > to ){
                    critical_link.push_back( make_pair( to , v ) ) ;
                }
                else{
                    critical_link.push_back( make_pair( v , to ) ) ;
                }
            }
        }
    }
}

void finding_bridge()
{
    memset( used , false , sizeof(used) ) ;

    for( int i = 0 ; i < MAX ; i++ ){
        tin[i] = -1 ;
        fup[i] = -1 ;
    }
    timer = 0 ;


    for( int i = 0 ; i < node ; i++ ){
        if( !used[i] ){
            dfs( i ) ;
        }
    }

    for( int i = 0 ; i < MAX ; i++ ){
        g[i].clear() ;
    }
}

int main()
{
    int t = 1 ;
    while( cin >> node ){
        for( int i = 0 ; i < node ; i++ ){
            int n  ;
            char ch ;
            cin >> n >> ch >> edge >> ch ;
            for( int j = 0 ; j < edge ; j++ ){
                int a ; cin >> a ;
                g[n].push_back( a ) ;
                g[a].push_back( n ) ;
            }

        }

        finding_bridge() ;

        if( critical_link.size() == 0 ){
            cout << "0 critical links" << endl ;
        }
        else{
            sort( critical_link.begin() , critical_link.end() , cmp ) ;
            cout << critical_link.size() << " critical links" << endl ;
            for( int i = 0 ; i < critical_link.size() ; i++ ){
                cout << critical_link[i].first << " - " << critical_link[i].second << endl ;
            }
        }
        cout << endl ;
        critical_link.clear() ;
    }
}



