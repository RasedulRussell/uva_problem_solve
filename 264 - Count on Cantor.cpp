#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

int main()
{
    ull colam[50000] ;
    colam[1] = 1 ;
    for( int i = 2 ; i < 50000 ; i++ ){
        if( i%2 == 0 ){
            colam[i] = colam[i-1]+1 ;
        }
        else{
            ull previous = (( i-1 )*i)/2 ;
            colam[i] = previous + i ;
        }
    }

    ull n ;
    ull a = 0 ;
    while( cin >> n ){
        ull col ;
        for( int i = 1 ; i < 50000 ; i++ ){
            ull total = ((i)*(i+1))/2 ;
            if( total >= n ){
                col = i ;
                break ;
            }
        }

        ull colamStart = colam[col] ;
        ull rowStart ;
        ///cout << col << endl ;
        ull x , y ;

        if( col%2 == 0 ){
            rowStart = colamStart + ( col-1 ) ;
        }
        else{
            rowStart = colamStart - ( col - 1 ) ;
        }

        ull difference ;

        if( col%2 == 0 ){
            difference = n - colamStart ;
            x = 1 ; y = col ;
            x =x + difference ;
            y =y - difference ;
        }
        else{
            difference = n - rowStart ;
            x = col ; y = 1 ;
            x = x - difference ;
            y = y + difference ;
        }
        cout << "TERM " << n << " IS " << x << "/" << y << endl ;
    }
}





