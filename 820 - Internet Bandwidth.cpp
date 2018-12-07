#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll V , sorce , sink;
ll Capacity[505][505];
ll parent[505];

void INI()
{
    for( int i = 0; i < 150; i++ ){
        for( int j = 0; j < 150; j++ ){
            Capacity[i][j] = 0;
        }
    }
}

bool BFS()
{
    bool visit[150];
    memset( visit, false , sizeof( visit ) );
    queue<ll>q;
    q.push( sorce );
    visit[sorce] = true;
    parent[sorce] = -1;

    while( !q.empty() ){
        int u = q.front();
        q.pop();
        for( int i = 1; i <= V; i++ ){
            if( Capacity[u][i] > 0 && visit[i] == false ){
                parent[i] = u;
                visit[i] = true;
                q.push( i ) ;
            }
        }
        if( visit[sink] ){
            return true;
        }
    }

    return false;
}

ll min( ll a , ll b )
{
    return (a<=b)?a:b;
}

ll max( ll a , ll b )
{
    return (a>=b)?a:b ;
}

ll max_flow( )
{
    ll maxFlow = 0 ;
    while( BFS()){
        ll minFlow = 1000000;
        for( int i = sink; i != sorce; i = parent[i] ){
            int u = parent[i] ;
            minFlow = min( minFlow , Capacity[u][i] );
        }

        for( int i = sink; i != sorce; i = parent[i] ){
            int u = parent[i];
            Capacity[u][i] -= minFlow;
            Capacity[i][u] += minFlow;
        }
        maxFlow += minFlow ;
    }
    return maxFlow;
}


int main()
{
    int t = 1 ;
    while( cin >> V && V ){

        int m ;
        cin >> sorce >> sink >> m;
        INI();

        for( int i = 0; i < m; i++ ){
            int a , b , c;
            cin >> a >> b >> c;
            Capacity[a][b] +=c ;
            Capacity[b][a] +=c;
        }
        cout << "Network " << t++ << endl ;
        cout << "The bandwidth is " << max_flow() << "." << endl << endl ;
    }
    return 0;
}





