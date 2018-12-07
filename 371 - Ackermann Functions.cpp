#include<bits/stdc++.h>

using namespace std ;

int main()
{
    long long a, b ;
    while( cin >> a >> b )
    {
        if( a==0&&b==0 )return 0 ;
        long long aa = a, bb = b ;
        if( aa > bb )
        {
            long long temp = aa ;
            aa = bb ;
            bb = temp ;
        }
        long long term = 0 ;
        long long n ;
        for( long long i = bb ; i >= aa ; i-- )
        {
            long long p = i ;
            long long count = 1 ;
            if( p%2==0 )
            {
                p =p/2 ;
            }
            else
            {
                p = 3*p + 1 ;
            }
            while( p!=1 )
            {
                if( p%2==0 )
                {
                    p =p/2 ;
                }
                else
                {
                    p = 3*p + 1 ;
                }
                count++ ;
            }
            if( count >= term ){
                term = count ;
                n = i ;
            }
        }
        ///Between 1 and 20, 18 generates the longest sequence of 20 values.
        cout << "Between " << aa << " and " << bb << ", " << n << " generates the longest sequence of " << term << " values." << endl ;
    }
}
