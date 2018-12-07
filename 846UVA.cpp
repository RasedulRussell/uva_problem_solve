#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

int main()
{
    int test ;
    cin >> test ;

    ll x , y ;
    while( test-- ){
        cin >> x >> y ;

        ll sum = 0 ;
        for( int i = 1; ; i++ ){
            if( sum*2 ==  abs( x-y ) ){
                cout << (i-1)*2 << endl;
                break;
            }

            sum += i ;

        }
    }
}
