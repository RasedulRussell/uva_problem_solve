#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

ll f( vector<ll>&a )
{
    ll result = a[0] ;

    for( int i = 0; i < a.size(); i++ ){
        ll temp = a[i] ;
        for( int j = i+1; j < a.size(); j++ ){
            result = max( result , temp );
            temp = temp*a[j] ;
            ///cout << temp << endl ;
        }
        result = max( result , temp );
    }
    return result ;
}

int main()
{
    ofstream myfile ;
    myfile.open("787.txt") ;
    ll a ;
    int t = 1 ;
    while( cin >> a ){
        vector<ll>number;
        while( 1 ){
            if( a == -999999 ){
                break;
            }
            number.push_back( a );
            cin >> a ;
        }
        cout << f( number ) << endl ;
        myfile << f( number ) << endl ;
    }
}
