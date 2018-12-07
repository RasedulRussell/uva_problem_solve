#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;

int main()
{
    ull n ;
    while( cin >> n && n != 0 ){
        ull lcm = 1 ;
        for( ull i = 2 ; i <= n ; i++ ){
            lcm = (lcm*i)/__gcd( lcm , i );
        }
        cout << lcm << endl ;
    }
    return 0 ;
}
