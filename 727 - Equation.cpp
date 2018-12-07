#include<bits/stdc++.h>

using namespace std ;

int main( )
{
    string temp ;
    int test, t ;
    cin >> test ;
    getchar( ) ;
    getchar( ) ;
    for( t = 1 ; t <= test ; t++ )
    {
        vector<string>exp ;
        exp.push_back( "(" ) ;
        string s ;
        while( getline( cin, s ) )
        {
            if( s == "" )break ;
            stringstream st ;
            st << s ;
            st >> temp ;
            exp.push_back( temp ) ;
        }
        exp.push_back( ")" ) ;
        vector<string>P ;
        stack<string>stk ;
        for( int i = 0 ; i < exp.size( ) ; i++ )
        {
            temp = exp[i] ;
            ///cout << "take " << temp << endl ;
            if( temp[0] >= '0' && temp[0] <= '9' )
            {
                P.push_back( temp ) ;
                ///cout << "push in p " << temp << endl ;
            }
            else if( temp == "+" || temp == "*" || temp == "-" || temp == "/" )
            {
                if( temp == "+" || temp == "-" )
                {
                    while( !stk.empty() && ( stk.top() == "+" || stk.top() == "-" || stk.top() == "*" || stk.top() == "/" ) )
                    {
                        ///cout << "push in p  " << stk.top() << endl ;
                        P.push_back( stk.top() ) ;
                        stk.pop( ) ;
                    }
                    ///stk.push( temp ) ;
                }
                else if( temp == "*" || temp == "/" )
                {

                    ///{
                        while( !stk.empty() && ( stk.top( ) == "*" || stk.top( ) == "/" ) )
                        {
                            ///cout << "push  in p " << stk.top() << endl ;
                            P.push_back( stk.top( ) ) ;
                            stk.pop( ) ;
                        }
                    ///}
                   /// stk.push( temp ) ;
                }
                ///cout << "push in stack " << temp << endl ;
                stk.push( temp ) ;
            }
            else
            {
                if( temp == "(" )
                {
                    ///cout << "push in stack " << temp << endl ;
                    stk.push(temp ) ;
                }
                else
                {
                    while( stk.top( ) != "(" )
                    {
                        ///cout << "push " << stk.top() << endl ;
                        P.push_back( stk.top() ) ;
                        stk.pop( ) ;
                    }
                    stk.pop() ;
                }
            }
        }
        for( int i = 0 ; i < P.size( ) ; i++ )
        {
            cout << P[i] ;
        }
        cout << endl ;
        if( t != test ){
            cout << endl ;
        }
    }
}
