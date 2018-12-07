#include<bits/stdc++.h>

using namespace std ;

string equation ;

int main()
{
    ///cout << floor( 3/2 ) << endl ;
    int test ; cin >> test ;
    while( test-- ){
        cin >> equation ;
        vector<pair<int,bool>>xx ;
        vector<pair<int,bool>>cc ;
        bool flag = true ;
        int x = 0 ;
        int constant = 0 ;
        char operation = '+' ;
        for( int i = 0 ; i < equation.size( ) ;  ){
            int gun = 1 ;
            bool bal = true ;
            if( equation[i] == '=' ){
                operation = equation[i] ;
                flag = false ;
                i++ ;
                continue ;
            }
            if( equation[i] == '+' || equation[i] == '-' ){
                operation = equation[i] ;
                i++ ; continue ;
            }
            ///cout << operation << endl ;
            if( operation == '-' ){
                gun = -1 ;
            }
            int temp = 0 ;
            if( equation[i] >= '0' && equation[i] <= '9' && i < equation.size() ){
                while( equation[i] >= '0' && equation[i] <= '9' ){
                    temp = temp*10 + ( equation[i] - '0' ) ;
                    bal = false ;
                    i++ ;
                }
            }
            if( equation[i] == 'x' ){
                if( temp == 0 && bal == true ){
                    temp = 1 ;
                }
                i++ ;
                xx.push_back( make_pair( temp*gun , flag ) ) ;
            }
            else{
                cc.push_back( make_pair( temp*gun , flag ) );
            }
            ///i++;
        }
        for( int i = 0 ; i < xx.size() ; i++ ){
            pair<int,bool>p=xx[i] ;
            if( p.second ){
                x += p.first ;
            }
            else{
                x -= p.first ;
            }
        }
        for( int i = 0 ; i < cc.size() ; i++ ){
            pair<int,bool>p=cc[i] ;
            if( p.second ){
                constant -= p.first ;
            }
            else{
                constant += p.first ;
            }
        }
        ///cout << constant << " " << x << endl ;
        if( constant == 0 && x == 0 ){
            cout << "IDENTITY" << endl ;
        }
        else if( constant != 0 && x == 0 ){
            cout << "IMPOSSIBLE" << endl ;
        }
        else{
            ///cout << constant << "  " << x << endl ;
            double ans = (double)(constant*1.0/x*1.0) ;
            ///cout << ans << endl ;
            ans = floor( ans ) ;
            if(ans==0)ans=0;
            cout << ans << endl ;
        }
    }
}

