#include<bits/stdc++.h>

using namespace std ;

void rigth_dari( int sz )
{
    for( int i = 0 ; i < sz+1 ; i++ ){
        cout << " " ;
    }
    cout << "|" ;
}

void left_dari( int sz )
{
    cout << "|" ;
    for( int i = 0 ; i < sz+1 ; i++ ){
        cout << " " ;
    }
}

void gol( int sz )
{
    cout << "|" ;
    for( int i = 0 ; i < sz ; i++ ){
        cout << " " ;
    }
    cout << "|" ;
}

void dari( int sz )
{
    cout << " " ;
    for( int i = 0 ; i < sz ; i++ ){
        cout << "-" ;
    }
    cout << " " ;
}

void faka( int sz )
{
    cout << " " ;
    for( int i = 0 ; i < sz ; i++ ){
        cout << " " ;
    }
    cout << " " ;
}

void base1( string num , int sz )
{
    for( int i = 0 ; i < num.size( ) ; i++ ){
        if( num[i] == '1' || num[i] == '4' ){
            faka( sz ) ;
        }
        else{
            dari( sz ) ;
        }
        if( i != num.size( ) - 1 ){
            cout << " " ;
        }
    }
}

void base3( string num , int sz )
{
    for( int i = 0 ; i < num.size( ) ; i++ ){
        if( num[i] == '1' || num[i] == '4' || num[i] == '7' ){
            faka( sz ) ;
        }
        else{
            dari( sz ) ;
        }
        if( i != num.size( ) -1 ){
            cout << " " ;
        }
    }
}

void bas2( string num , int sz )
{
    for( int i = 0 ; i < num.size( ) ; i++ ){
        if( num[i] == '1' || num[i] == '7' || num[i] == '0' ){
            faka( sz ) ;
        }
        else{
            dari( sz ) ;
        }
        if( i != num.size( ) - 1 ){
            cout << " " ;
        }
    }
}

void midleup( string num , int sz )
{
    for( int i = 0 ; i < num.size( ) ; i++ ){
        if( num[i] == '1' || num[i] == '3' || num[i] == '2' || num[i] == '7' ){
            rigth_dari( sz ) ;
        }
        else if( num[i] == '8'  || num[i] == '4' || num[i] == '9' || num[i] == '0' ){
            gol( sz ) ;
        }
        else if( num[i] == '5' || num[i] == '6' ){
            left_dari( sz ) ;
        }
        if( i != num.size( ) - 1 ){
            cout << " " ;
        }
    }
}

void midlow( string num , int sz )
{
    for( int i = 0 ; i < num.size( ) ; i++ ){
        if( num[i] == '6' || num[i] == '8' || num[i] == '0' ){
            gol( sz ) ;
        }
        else if( num[i] == '1' || num[i] == '3' || num[i] == '4' || num[i] == '5' || num[i] == '7' || num[i] == '9' ){
            rigth_dari( sz ) ;
        }
        else if( num[i] == '2' ){
            left_dari( sz ) ;
        }
        if( i != num.size() - 1 ){
            cout << " " ;
        }
    }
}

int main()
{
    int sz ;
    string number ;
    int p = 0 ;
    while( cin >> sz >> number ){
        if( sz == 0 && number == "0" ){
         ///cout << endl ;
        return 0 ;
        }
        int siz = sz*2 + 3 ;
        for( int i = 1 ; i <= siz ; i++ ){
                if( i == 1  ){
                    base1( number , sz ) ;
                }
                else if( i == 2+sz ){
                    bas2( number , sz ) ;
                }
                else if( i == siz ){
                    base3( number , sz ) ;
                }
                else if( i <= sz+1 )
                {
                    midleup( number , sz ) ;
                }
                else
                {
                    midlow( number , sz ) ;
                }
                cout << endl ;
        }
        cout << endl ;
    }
}
