#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

vector<pair<ll , ll>>graph[10000] ;
bool visit[10000] ;
ll cost[10000] ;
ll first ;
void saf()
{
    for( int i = 0 ; i < 10000 ; i++ ){
        cost[i] = 1000000000 ;
        visit[i] = true ;
        graph[i].clear( ) ;
    }
}

bool cmp( pair<ll,ll>a , pair<ll,ll>b )
{
    return a.second < b.second ;
}

void dj( int u  )
{
    visit[u] = false ;
    priority_queue<pair<ll,ll>>pq ;
    pq.push( make_pair( u , first ) ) ;
    while( !pq.empty() ){
      pair<ll,ll>u = pq.top() ; pq.pop() ;
      if( cost[u.first] < u.second)continue ;
      for( int i = 0 ; i < graph[u.first].size( ) ; i++ ){
        pair<ll,ll>v = graph[u.first][i] ;
        if( cost[v.first] > cost[u.first]+u.second ){
            cost[v.first] = cost[u.first]+u.second ;
            pq.push( make_pair( v.first , cost[v.first] )) ;
        }
      }
    }
}

int main()
{
    ll n , m;
    while( cin >> n >> m ){
        saf( ) ;
        ll a ;
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= m ; j++ ){
                cin >> a ;
                if( i == 1 && j == 1 ){
                    first = a;
                }
                graph[i].push_back( make_pair( j , a ) ) ;
                graph[j].push_back( make_pair( i , a ) ) ;
            }
        }
        dj( 1 ) ;
        cout << cost[m] << endl ;
    }
}
