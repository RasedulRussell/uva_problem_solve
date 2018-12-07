#include<bits/stdc++.h>

using namespace std ;


int main( )
{
    int test, t ;
    cin >> test ;
    getchar( ) ;
    for( t = 1 ; t <= test ; t++ )
    {
        string line ;
        getline( cin, line ) ;
        double U = 0.0, I = 0.0, P = 0.0 ;
        bool ii = true ;
        bool pp = true ;
        bool uu = true ;
        for( int i = 0 ; i < line.size( ) ; i++ )
        {
            char ch  ;
            if( line[i] == '=' )
            {
                ch = line[i-1] ;
                if( line[i+1] == '-' ){
                    i++ ;
                }
                ///cout << "i " << i << " " << ch << endl ;
                ///i++ ;
                double temp = 0 ;
                bool point = false ;
                long long tt = 10.0 ;
                while( 1 ){
                    i++ ;
                    if( line[i] == 'W' || line[i] == 'V' || line[i] == 'A' ){
                        break ;
                    }
                    else if( line[i] == 'm' ){
                        temp /= 1000.0 ;
                        break ;
                    }
                    else if( line[i] == 'k' ){
                        temp *= 1000.0 ;
                        break ;
                    }
                    else if( line[i] == 'M' ){
                        temp *= 1000000.0 ;
                        break ;
                    }
                    double n = line[i] - 48.0 ;
                    ///cout << n << endl ;
                    if( n == -2.0 ){
                        point = true ;
                        continue ;
                    }
                    if( point ){
                        temp += n/tt ;
                        tt *= 10.0 ;
                    }
                    else{
                        temp = temp*10.0 + n ;
                    }
                }
                ///cout << temp << endl ;
                if( ch == 'I' ){
                    I = temp ;
                    ii = false ;
                }
                else if( ch == 'U' ){
                    U = temp ;
                    uu = false ;
                }
                else if( ch == 'P' ){
                    P = temp ;
                    pp = false ;
                }
            }
        }
        cout << "Problem #" << t << endl ;
        if( ii  )
        {
            ///cout << P/U << endl ;
            printf( "I=%.2fA\n",P/U ) ;
        }
        else if( pp )
        {
            ///cout << I*U << endl ;
            printf( "P=%.2fW\n",I*U ) ;
        }
        else if( uu  )
        {
            printf( "U=%.2fV\n",P/I ) ;
        }
        cout << endl ;
        ///cout << "P " <<  P << endl << "I " <<  I << endl << "U " << U << endl ;
    }
    return 0 ;
}
