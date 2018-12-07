#include<bits/stdc++.h>

using namespace std ;

vector<vector<int>>r ;

bool isPrime( int n )
{
    for( int i = 2 ; i < n ; i++ ){
        if( n%i == 0 ){
            return false ;
        }
    }
    return true ;
}

void vectorPrint( vector<int>v )
{
    for( int i = 0 ; i < v.size() ; i++ ){
        cout << v[i] ;
        if( i == v.size()-1 ){
            cout << endl ;
        }
        else{
            cout << " " ;
        }
    }
    ///cout << endl ;
}

void f( vector<int>result , int n , bool flag[] )
{

}

bool fun( vector<int>f , int a )
{
    for( int i = 0 ; i < f.size() ; i++ ){
        if( f[i]==a ){
            return false ;
        }
    }
    return true ;
}

int main()
{
    int n ;
    int t = 1 ;
    while( cin >> n ){
        queue<vector<int>>q ;
        vector<int>v ;
        v.push_back( 1 ) ;
        q.push( v ) ;
        if( t > 1 ){
            cout << endl ;
        }
        cout << "Case " << t++ << ":" << endl ;
        vector<vector<int>>re ;
        while( !q.empty() ){
            vector<int>temp = q.front() ;
            q.pop() ;
            for( int i = 1 ; i <= n ; i++ ){
                int a = temp[temp.size()-1] ;
                vector<int>bb = temp ;
                if( isPrime( a+i ) == true && fun( bb , i ) == true ){
                    bb.push_back(i) ;
                    if( bb.size()==n ){
                        re.push_back( bb ) ;
                    }
                    else{
                        q.push( bb ) ;
                    }
                }
            }
        }
        for( int i = 0 ; i < re.size() ; i++ ){
            vector<int>vv = re[i] ;
            int a = vv[vv.size()-1] ;
           if( isPrime( a+1 ) == true ){
                vectorPrint( re[i] ) ;

            }
        }
        //if( t > 1 ){
            ///cout << endl ;
        //}
        re.clear() ;
    }
}

