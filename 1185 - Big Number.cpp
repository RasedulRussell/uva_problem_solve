#include<bits/stdc++.h>

using namespace std ;


int main()
{
    int t ;
    cin >> t ;
    while( t-- ){
        long long n ;
        cin >> n ;
        if( n ==1 ){
            cout << "1" << endl ;
            continue ;
        }
        double x = ((n*log10(n/M_E)+log10(2*M_PI*n)/2.0));
        cout << (long long)floor(x)+1 << endl ;
    }
    return 0 ;
}
