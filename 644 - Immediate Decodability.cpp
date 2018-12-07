#include<bits/stdc++.h>

using namespace std ;


int main( )
{
    int test = 1 ;
    string temp ;
    while( cin >> temp ){
        vector<string>code ;
        code.push_back( temp ) ;
        while( 1 ){
            cin >> temp ;
            if( temp == "9" ){
                break ;
            }
            code.push_back( temp ) ;
        }
        map<string , int>huha ;
        map<string , int>::iterator itr1 ;
        vector<string>::iterator itr ;
        for( int i = 0 ; i < code.size() ; i++ ){
            temp = code[i] ;
            int sz = temp.size() ;
            ///huha[temp]++ ;
            for( int j = 0 ; j < code.size() ; j++ ){
                if( code[j].size() >= sz ){
                    string t = code[j].substr( 0 , sz ) ;
                    ///cout << t << endl ;
                    ///itr = find( code.begin() , code.end() , t ) ;
                    if( t == temp ){
                        huha[t]++ ;
                    }
                }
            }
        }
        bool flag = true ;
        for( itr1 = huha.begin() ; itr1 != huha.end() ; ++itr1 ){
            if( itr1->second >= 2 ){
                flag = false ;
                break ;
            }
        }
        if( flag ){
            cout << "Set " << test++ << " is immediately decodable" << endl ;
        }
        else{
            cout << "Set " << test++ << " is not immediately decodable" << endl ;
        }
        code.clear() ;
        huha.clear() ;
    }
    return 0 ;
}
