#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;
map<string , int>position ;
map<string , ll>main_map ;
/*
negative, zero, one, two, three, four, five, six, seven, eight, nine, ten,
eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen,
twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety, hundred,
thousand, million
*/

int check( vector<string>all , int po )
{
    for( int i = po  ; i < all.size() ; i++ ){
        if(all[i] == "hundred" || all[i] == "million" || all[i] == "thousand" ){
               return position[all[i]] ;
        }
    }
    return po ;
}

int main( )
{
    position["million"] = 3 ;
    position["hundred"] = 1 ;
    position["thousand"] = 2 ;

    main_map["one"] = 1 ; main_map["four"] = 4 ; main_map["five"] = 5 ;
    main_map["zero"] = 0 ; main_map["six"] = 6 ; main_map["seven"] = 7 ;
    main_map["two"] = 2 ; main_map["eight"] = 8 ; main_map["nine"] = 9 ;
    main_map["three"] = 3 ; main_map["ten"] = 10 ; main_map["eleven"] = 11 ;
    main_map["twelve"] = 12 ; main_map["thirteen"] = 13 ; main_map["fourteen"] = 14 ;
    main_map["fifteen"] = 15 ; main_map["sixteen"] = 16 ; main_map["seventeen"] = 17 ;
    main_map["eighteen"] = 18 ;main_map["nineteen"] = 19 ; main_map["twenty"] = 20 ;
    main_map["forty"] = 40 ; main_map["thirty"] = 30 ; main_map["fifty"] = 50 ; main_map["sixty"] = 60 ;
    main_map["seventy"] = 70 ; main_map["eighty"] = 80 ; main_map["ninety"] = 90 ; main_map["hundred"] = 100 ;
    main_map["thousand"] = 1000 ; main_map["million"] = 1000000 ;
    string line ;
    while( getline( cin , line ) ){
        ///line = line ;
        stringstream st ;
        st << line ;
        string temp1 ;
        ll ans = 0 ;
        bool flag = true ;
        vector<string>all ;
        while( st >> temp1){
            if( temp1 == "negative" ){
                flag = false ;
                continue ;
            }
            all.push_back( temp1 ) ;
        }
        ///cout << all.size( ) << endl ;
        ll temp = 0 ;
        for( int i = 0 ; i < all.size( ) ; i++ ){
            string first = all[i] ;
            if(all[i] == "hundred" || all[i] == "million" || all[i] == "thousand" ){
               int j =  check( all , i+1 ) ;
               if( position[all[i]] < j ){
                temp = temp*main_map[all[i]] ;
               }
               else{
                ans = ans + temp*main_map[all[i]] ;
                temp = 0 ;
               }
            }
            else{
                temp = temp + main_map[all[i]] ;
            }
        }
        if( temp != 0 ){
            ans = ans + temp ;
        }
        if( flag ){
            cout << ans << endl ;
        }
        else{
            ///cout << "ok" << endl ;
            cout << -1*ans << endl ;
        }
    }
    return  0 ;
}



/*
st >> temp2 ;
            if( temp2 == "hundred" || temp2 == "million" || temp2 == "thousand" ){
                ll temp = main_map[temp1] ;
                st >> temp1 ;
                ans += main_map[temp1]*temp ;
            }
            else{
                ll temp = main_map[temp1] ;
                st >> temp1 ;
                ///cout << main_map[temp1] + main_map[temp2] << endl ;
                ans = ans + main_map[temp1] + temp ;
            }
            ///cout << ans << endl ;

        */





















