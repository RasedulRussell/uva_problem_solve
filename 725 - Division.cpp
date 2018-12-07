#include<bits/stdc++.h>

using namespace std ;


typedef unsigned long long ull ;
typedef long long ll ;
typedef vector<ull> uv ;
typedef vector<ll> lv ;

void input( ll arr[] , ll n )
{
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i] ;
    }
}

bool fun( ll arr[] , ll n )
{
    for( int i = n-1 ; i>= 1 ; i-- ){
        if( arr[i] > arr[i-1] ){
            return true ;
        }
    }
    return false ;
}

int fun2( ll arr[] , ll n )
{
    int cnt = 0 ;
    ll m = arr[n-1] ;
    for( int i = n-1 ; i >= 1 ; i-- ){
        if( arr[i] == m ){
            cnt++ ;
            continue ;
        }
        break ;
    }
    return cnt ;
}

int fghij ;
bool check( ll ans , ll n )
{
    fghij = 0 ;
   int arr[10] ;
   memset( arr , 0 , sizeof( arr ) ) ;
   while( ans > 0 ){
    arr[ans%10]++ ;
    ans/=10;
   }
   while( n > 0 ){
    arr[n%10]++ ;
    if( arr[n%10] >= 2 ){
        return false ;
    }
    fghij++ ;
    n/=10 ;
   }
   if( fghij < 4 ){
    return false ;
   }
   if( fghij == 4 ){
    arr[0]++ ;
   }
   if( arr[0] >= 2 ){
    return false ;
   }
   return true ;
}

void print( ll arr[] , ll n )
{
    for( int i = 0 ; i < n ; i++ ){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

int main( )
{
    int n ;
    int t = 0 ;
    while( cin >> n && n != 0 ){
        if( t != 0 ){
            cout << endl ;
        }
        t = 2 ;
        bool flag = true ;
        for( int i = 1 ; i <= 9 ; i++ ){
            for( int j = 0 ; j <= 9 ; j++ ){
                for( int k = 0 ; k <= 9 ; k++ ){
                    for( int l = 0 ; l <= 9 ; l++ ){
                        for( int m = 0 ; m <= 9 ; m++ ){
                            set<int>s ;
                            s.insert( i ) ;s.insert( j ) ;s.insert( k ) ;s.insert( l ) ;s.insert( m ) ;
                            if( s.size( ) == 5 ){
                                ll ans = i ;
                                ans = ans*10 + j;
                                ans = ans*10 + k ;
                                ans = ans*10 + l ;
                                ans =ans*10 + m ;
                                if( ans%n == 0 && check( ans , ans/n ) == true  ){
                                    if( fghij < 4 ){
                                        continue ;
                                    }
                                    if( (i == 0 || j == 0 || k == 0 || l == 0||m==0) && fghij == 4 ){
                                        continue ;
                                    }
                                    cout << i << j << k << l << m << " / "  ;
                                    if( fghij == 4 ){
                                        cout << "0" ;
                                    }
                                    cout << ans/n << " = " << n << endl ;
                                    flag = false ;

                                }
                            }
                        }
                    }
                }
            }
        }
    if( flag ){
        cout << "There are no solutions for " << n << "." <<  endl ;
    }
    }
}
