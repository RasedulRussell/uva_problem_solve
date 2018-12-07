#include<bits/stdc++.h>

using namespace std ;

map<long long, int>visit ;
vector<int>graph[100000] ;
int cnt = 0 ;

void BFS( pair<int,int>p )
{
    int u = p.first ;
    int ttl = p.second ;
    ///cout << "sourch " << u << " " << ttl << endl ;
    queue<int>Q ;
    Q.push( u ) ;
    visit[u] = 0 ;
   /// cout << visit[u] << " " << u << endl ;
    ///int current = 1 ;
    while( !Q.empty() )
    {
        u = Q.front() ;
        Q.pop() ;
        ///cout << "yes i am into queue" << endl ;
        for( int i = 0 ; i < graph[u].size( ) ; i++ )
        {
            int v = graph[u][i] ;
            if( visit[u]+1 <= ttl && visit[v] == -1 )
            {
                if( visit[u] + 1 < ttl )
                {
                    Q.push( v ) ;
                }
                visit[v] = visit[u]+1 ;
                ///cout << v << " " << visit[v] << endl ;
            }
        }
    }
}

int main( )
{
    int n ;
    while( cin >> n && n != 0 )
    {
        set<int>number ;
        for( int i = 0 ; i < n ; i++ )
        {
            int u,v;
            cin >> u >> v ;
            if( u == v ){
               ///graph[u].push_back( v ) ;
                visit[u] = -1 ;
                number.insert( u ) ;
                ///continue ;
            }else{
            graph[u].push_back( v ) ;
            graph[v].push_back( u ) ;
            visit[u] = -1 ;
            visit[v] = -1 ;
            number.insert( u ) ;
            number.insert( v ) ;
            }
        }
        vector<pair<int,int> >quary ;
        while( 1 )
        {
            int u, v ;
            cin >> u >> v ;
            if( u == 0 && v == 0 )
            {
                break ;
            }
            quary.push_back( make_pair( u, v ) ) ;
        }
        map<long long, int > :: iterator itr ;
        for( int i = 0 ; i < quary.size() ; i++ )
        {
            pair<int,int>p = quary[i] ;
            BFS( p ) ;
            int count = 0 ;
            ///visit[p.first] = -1 ;
            for( itr = visit.begin() ; itr != visit.end( ) ; ++itr )
            {
                if( itr->second == -1 )
                {
                    ///cout<<itr->first << " " << itr->second << endl ;
                    count++ ;
                }
                ///cout<<itr->first << " " << itr->second << endl ;
                itr->second = -1 ;
            }
            ///Case 1: 5 nodes not reachable from node 35 with TTL = 2.
            cout << "Case " << ++cnt << ": " << count << " nodes not reachable from node " << p.first << " with TTL = " << p.second << "." << endl ;
        }
        visit.clear() ;
        set<int>::iterator it ;
        for( it = number.begin() ; it!=number.end() ; ++it )
        {
            graph[*it].clear( ) ;
        }
    }
    return 0 ;
}
