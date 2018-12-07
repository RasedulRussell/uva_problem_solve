#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;
typedef long long ll ;
int r8[8] = { -1 , -1 , 0 , 1,1,1,0, -1 };
int c8[8] = { 0 , 1 , 1 ,1, 0, -1,-1,-1 };
int r4[] = { 0 , 0 , 1 , -1  } ;
int c4[] = { 1 , -1 , 0 , 0 } ;

void input( ll arr[] , ll n )
{
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i] ;
    }
}

ll gcd( ll a , ll b )
{
    if( b == 0 ){
        return a ;
    }
    return gcd( b , a%b ) ;
}

bool fun( char c )
{
    char ch[] = { 'A' , 'E' , 'I' , 'O' , 'U' , 'Y' } ;
    for( int i = 0 ; i < 6 ; i++ ){
        if( ch[i] == c )return true ;
    }
    return false ;
}

bool cmp( pair<ll,ll>p1 , pair<ll,ll>p2 )
{
    return ( p1.first < p2.first ) ;
}

ll n , total ;
vector<ll>result ;
ll dif = 100000000 ;
ll sum ;

void p( vector<ll>v , ll s )
{
    if( dif >= abs( total-s ) ){
        dif = abs( total-s ) ;
        result = v ;
        sum = s ;
    }
    /*for( int i = 0 ; i < v.size( ) ; i++ ){
        cout << v[i] << " " ;
    }
    cout << endl <<  "total " << s << endl ;*/
}

void f( ll arr[] , ll po , ll now , vector<ll>store )
{
     if( po == n || now > total ){
        p( store , now ) ;
        return ;
      }
        f( arr , po+1 , now , store ) ;
        if( now+arr[po] <= total ){
           store.push_back( arr[po] ) ;
           f( arr , po+1 , now+arr[po] , store  ) ;
        }
}

int main( )
{
    while( cin >> total >> n ){
        ll arr[n+1] ;
        for( int i = 0 ;i < n ; i++ ){
            cin >> arr[i] ;
        }
        vector<ll>st ;
        f( arr , 0 , 0 , st ) ;
        for( int i = 0 ; i < result.size() ; i++ ){
            cout << result[i] << " " ;
        }
        cout << "sum:" << sum << endl ;
        result.clear() ;
        dif = 10000000 ;
    }
    return 0 ;
}




