#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

ll gcd( ll a , ll b )
{
    if( b == 0 ){
        return a ;
    }
    return gcd( b , a%b ) ;
}

int main()
{
    ll n ;
    while( cin >> n ){
        ll nn = sqrt( n ) ;
        bool arr[n+2] ;
        memset( arr , true , sizeof(arr) ) ;
        int cnt = 0 ;
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = i+1 ; j <= n ; j++ ){
                ll a = i*i + j*j ;
                ll b = sqrt( a ) ;
                if( b < j ){
                    break ;
                }
                if( b > j && b*b == a && gcd( i , gcd( j , b ) ) == 1 ){
                    cnt++ ;
                    arr[i]=false ;
                    arr[j] = false ;
                    arr[b] = false ;
                }
            }
        }
        int ans = 0 ;
        for( int i = 1 ; i <= n ; i++ ){
            if( arr[i] ){
                ans++ ;
            }
        }
        cout << ans << " " << cnt << endl ;
    }
}
