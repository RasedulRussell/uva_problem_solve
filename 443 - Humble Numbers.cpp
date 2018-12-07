#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;

vector<ull>humbleNumber ;

void process(  )
{
    queue<ull>q ;
    q.push( 1 ) ;
    map<ull , int>fre ;
    humbleNumber.push_back(1) ;
    while( humbleNumber.size() < 5842 )
    {
        ull a = q.front() ;
        q.pop() ;
        if( a*2 <= 2000000000 && fre[a*2] < 1 ){
            q.push( a*2 ) ;
            humbleNumber.push_back(a*2) ;
            fre[a*2]++ ;
        }
        if( a*3 <= 2000000000 && fre[a*3] < 1 ){
            q.push( a*3 ) ;
            humbleNumber.push_back(a*3) ;
            fre[a*3]++ ;
        }
        if( a*5 <= 2000000000 && fre[a*5] < 1 ){
            q.push( a*5 ) ;
            humbleNumber.push_back(a*5) ;
            fre[a*5]++ ;
        }
        if( a*7 <= 2000000000 && fre[a*7] < 1 ){
            q.push( a*7 ) ;
            humbleNumber.push_back(a*7) ;
            fre[a*7]++ ;
        }
    }
}

bool zero( ull n )
{
    while( n > 0 ){
        if( n%10 == 0 ){
            return true ;
        }
        n/=10 ;
    }
    return false ;
}

string numberPrefix( ull a )
{
    if( a >= 10 && a < 20 ){
        return "th" ;
    }
    ull aa = a ;
    aa/=10 ;
    if( aa%10 == 1 ){
        return "th" ;
    }
    if( a%10 == 1  ){
        return "st" ;
    }
    if( a%10 == 2  ){
        return "nd" ;
    }
    if( a%10 == 3  ){
        return "rd" ;
    }
    return "th" ;
}

int main()
{
    process() ;
    ///cout << humbleNumber.size() << endl;
    sort( humbleNumber.begin() , humbleNumber.end() ) ;
    int n ;
    while( cin >> n && n!=0 ){
        cout <<"The " << n << numberPrefix(n)
        << " humble number is " << humbleNumber[n-1] << "." << endl ;
    }
}
