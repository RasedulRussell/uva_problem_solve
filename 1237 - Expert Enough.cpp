#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;
typedef long long ll ;

struct element
{
    string name ;
    ull low ,high ;
    element( string _name , ull _l , ull _hi ){
      name = _name ; low = _l ;  high = _hi ;
    }
};

int main( )
{
    int t ;
    cin >> t ;
    for( int te = 0 ; te < t ; te++ ){
        if( te != 0 ){
            cout << endl ;
        }
        map<string , pair<ull , ull >>result ;
        int n ; cin >> n ;
        for( int i = 0 ; i < n ; i++ ){
            string name ;
            ull l , h ;
            cin >> name >> l >> h ;
            result[name] = make_pair( l , h ) ;
        }
        int quary ;
        cin >> quary ;
        for( int i = 0 ; i < quary ; i++ ){
            ull tk ; cin >> tk ;
            string huha ;
            int cnt = 0 ;
            for( map<string , pair<ull,ull>>::iterator itr = result.begin() ; itr != result.end() ; ++itr ){
                pair<ull,ull>p = itr->second ;
                if( p.first <= tk && p.second >= tk ){
                    huha = itr->first ;
                    cnt++ ;
                }
            }
            if( cnt == 0 || cnt >= 2 ){
                cout << "UNDETERMINED" << endl ;
            }
            else{
                cout << huha << endl ;
            }
        }
    }
}



