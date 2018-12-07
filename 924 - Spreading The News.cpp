
#include<bits/stdc++.h>

using namespace std ;

vector<int>graph[2509] ;
int visit[3000] ;
int max_day ;

void saf(  )
{
    for( int i = 0 ; i < 2504 ; i++ ){
        visit[i] = -1 ;
        ///graph[i].clear( ) ;
    }
}

void saf1(  )
{
    for( int i = 0 ; i < 2504 ; i++ ){
        ///visit[i] = -1 ;
        graph[i].clear( ) ;
    }
}

void bfs( int u )
{
    visit[u] = 0 ;
    queue<int>q ;
    q.push( u ) ;
    while( !q.empty( ) ){
        u = q.front( ) ; q.pop( ) ;
        for( int i = 0 ; i < graph[u].size( ) ; i++ ){
            int v = graph[u][i] ;
            if( visit[v] == -1 ){
                visit[v] = visit[u]+1 ;
                ///cout <<"helo " << visit[v] << endl ;
                max_day = max( max_day , visit[v] ) ;
                q.push( v ) ;
            }
        }
    }
}

int main()
{

    int n ;
    ///while(   ){
    cin >> n ;
    saf( ) ;
    for( int i = 0 ; i < n ; i++ ){
        int e ; cin >> e ;
        for( int j = 0 ; j < e ; j++ ){
            int a ; cin >> a ;
            graph[i].push_back( a ) ;
            ///cout << "yes" << endl ;
            ///graph[a].push_back( i ) ;
        }
    }
    int t ;
    cin >> t ;
    for( int i = 1 ; i <= t ; i++ ){
        saf( ) ;
        int sorce ; cin >> sorce ;
        max_day = 0 ;
        bfs( sorce ) ;
        visit[sorce] = -1 ;
        map<int , int>mp ;
        for( int k = 0 ; k < n ; k++ ){
            if( visit[k] != -1 ){
                mp[visit[k]]++ ;
            }
        }
        int m = 0 , day = 0 ;
        for( map<int , int>::iterator itr = mp.begin( ) ; itr != mp.end( ) ; ++itr ){
            int c = itr->first ; int d = itr->second ;
            if( d > m  ){
                m = d ; day = c ;
            }
        }
        if( day == 0 ){
            cout << "0" << endl  ;
        }
        else{
            cout << m << " " << day << endl ;
        }
    }
    saf1(  ) ;
    ///}
    return 0 ;
}
