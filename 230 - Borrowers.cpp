#include<bits/stdc++.h>


using namespace std ;

bool operator<( pair<string,string>a, pair<string,string>b )
{
    string A = a.second ;
    string B = b.second ;
    for( int i = 0 ; i < A.size( ) ; i++ )
    {
        if( i == A.size( )-1 || i == B.size( )-1 )
        {
            break ;
        }
        if( A[i] > B[i] )
        {
            return false ;
        }
    }
    return true ;
}

int main()
{
    int abal ;
    string  line ;
    vector< pair<string, string> >self ;
    while( getline( cin, line ) )
    {
        if( line == "END" )
        {
            break ;
        }
        stringstream st ;
        st << line ;
        string temp ;
        string book = "", auther = "" ;
        bool flag = false ;
        int i = 0 ;
        while( i < line.size() )
        {
            if( line[i-1]==' ' && line[i]== 'b' && line[i+1] == 'y' ){
                i += 2 ;
                flag = true ;
            }
            else if( flag ){
                book += line[i] ;
                i++ ;
            }
        }
        pair<string,string>pi( book, auther ) ;
        self.push_back( pi ) ;
    }
    sort( self.begin(), self.end() ) ;
    int sz = self.size( ) ;
    bool check[sz] ;
    memset( check, true, sizeof( check ) ) ;
    map<string,string>::iterator itr ;
    stack<string>RE ;
    string huha ;
    cout << self.size() << endl ;
    for( int i = 0 ; i < self.size( ) ; i++ )
    {
        cout << self[i].first << " " << self[i].second << endl ;
    }
    while( getline( cin, huha ) )
    {
        stringstream  st ;
        st << huha ;
        string operation, bok ;
        st >> operation ;
        if( operation == "SHELVE" )
        {
            while( !RE.empty() )
            {
                bok = RE.top() ;
                RE.pop() ;
                string pre ;
                for( int i = 0 ; i < self.size() ; i++ )
                {
                    bool huh = false ;
                    if( check[i] == true )
                    {
                        pre = self[i].first ;
                    }
                    if( self[i].first == bok && check[i] == false )
                    {
                        huh == true ;
                        check[i] = true ;
                        if( i == 0 )
                        {
                            cout << "Put " << bok << " first" << endl ;
                        }
                        else
                        {
                            cout << "Put " << bok << " after " << pre << endl ;
                        }
                    }
                    if( huh )
                    {
                        break ;
                    }
                }
            }
        }
        else if( operation == "BORROW" )
        {
            st >> bok ;
            for( int i = 0 ; i < self.size() ; i++ )
            {
                if( self[i].first == bok )
                {
                    check[i] = false ;
                    break ;
                }
            }
        }
        else if( operation == "RETURN" )
        {
            st >> bok ;
            RE.push( bok ) ;
        }
    }
    return 0 ;
}
