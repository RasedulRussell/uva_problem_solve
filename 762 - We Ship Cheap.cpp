#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

map<string , int>mp1 ;
map<int , string>mp2 ;
ull dis[100000] ;
ull parent[100000] ;
vector<int>graph[100000] ;
vector<int>path ;
bool visit[100000] ;

void allClear()
{
    memset( visit , false , sizeof( visit ) ) ;
    for( int i = 1 ; i < 100000 ; i++ ){
        graph[i].clear( ) ;
    }
    for( int i = 0 ; i < 100000 ; i++ ){
        dis[i] = 1000000 ;
        parent[i] = i ;
    }
    mp1.clear() ;
    mp2.clear() ;
}

void bfs( int u )
{
    visit[u] = true ;
    queue<int>q ;
    q.push( u ) ;

    while( !q.empty() ){
        u = q.front() ;
        q.pop() ;
        for( int i = 0 ; i < graph[u].size( ) ; i++ ){
            int v = graph[u][i] ;
            if( dis[v] > dis[u]+1 ){
                dis[v] = dis[u]+1 ;
                parent[v] = u ;
            }
            if( visit[v] == false ){
                visit[v] = true ;
                q.push( v ) ;
            }
        }
    }
}

int main()
{
    int n ;
    int t = 1 ;

    while( cin >> n ){

        allClear() ;
        int cnt = 1 ;

        if( t != 1 ){
            cout << endl ;
        }

        t = 22 ;

        for( int i = 0 ; i < n ; i++ ){

            string a , b ;
            cin >> a >> b ;

            if( mp1[a] == 0 ){
                mp1[a] = cnt ;
                mp2[cnt] = a ; cnt++ ;
            }
            if( mp1[b] == 0 ){
                mp1[b] = cnt ;
                mp2[cnt] = b ; cnt++ ;
            }
            graph[mp1[a]].push_back( mp1[b] ) ;
            graph[mp1[b]].push_back( mp1[a] ) ;
        }

        string s , d ;
        cin >> s >> d ;

        dis[mp1[s]] = 0 ;
        bfs( mp1[s] ) ;

        if( dis[mp1[d]] == 1000000 || mp1[s] == 0 || mp1[d] == 0 ){
            cout << "No route" << endl ; continue ;
        }

        int a = mp1[d] ;

        while( parent[a] != a ){
            path.push_back( a ) ;
            a = parent[a] ;
        }
        path.push_back( mp1[s] ) ;
        for( int i = path.size() - 1 ; i > 0 ; i-- ){
            cout << mp2[path[i]] << " " << mp2[path[i-1]] << endl ;
        }

        path.clear() ;
    }
}
