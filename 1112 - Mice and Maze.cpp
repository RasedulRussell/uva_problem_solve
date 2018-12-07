#include<bits/stdc++.h>

using namespace std ;

struct node{
    int u , cost ;
    node( int _u , int _cost ){
        u = _u ;
        cost = _cost ;
    }
};

struct edge{
    int v , w ;
    edge( int _v , int _w ){
        v = _v ;
        w = _w ;
    }
};

bool operator<( node A , node B ){
    return A.cost < B.cost ;
}

vector<edge>graph[101] ;
int n ;
int dis[101] ;

void djkstra( int src ){
    for( int i = 0 ; i<= n ; i++ ){
    dis[i] = 1000000000 ;
    }
    dis[src] = 0 ;
    priority_queue<node>pq ;
    pq.push( node( src , dis[src] ) ) ;
    while( !pq.empty() ){
        node u = pq.top() ;
        pq.pop() ;
        for( int i = 0 ; i < graph[u.u].size( ) ; i++ ){
            edge v = graph[u.u][i] ;
            if( dis[v.v] > v.w + u.cost ){
                dis[v.v] = v.w + u.cost ;
                pq.push( node( v.v , dis[v.v] ) )   ;
            }
        }
    }
}

int main( )
{
    int test ;
    cin >> test ;
    int t = 0 ;
    while( test-- ){
        if( t!=0 )
            cout<< endl ;
        t++ ;
        int exit , time , m ;
        cin >> n >> exit >> time >> m ;
        for( int i = 0 ; i < m ; i++ ){
            int u , v , w ;
            cin >> u >> v >> w ;
            graph[u].push_back( edge( v , w ) ) ;
        }
        int count = 0 ;
        for( int i = 1 ; i <= n ; i++ ){
           /// if( i != exit ){
                 ///   cout << i << " " ;
                djkstra( i ) ;
            ///}
           /// cout << dis[exit] << " " << i << endl ;
            if( dis[exit] <= time ){
                count++ ;
                ///cout << "coutn++ " << i << endl ;
            }
        }
        cout << count << endl  ;
        for( int i = 0 ; i < 101 ; i++ ){
            graph[i].clear( ) ;
        }
    }
    return 0 ;
}
