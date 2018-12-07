#include<bits/stdc++.h>

using namespace std ;



struct Point
{
    double x , y ;
    Point( double _x , double _y ){
      x = _x ; y = _y ;
    }
};

double sqr( double x )
{
    return x*x ;
}

int main()
{
    double PI = 3.141592653589793 ;
    int t = 0 ;
    Point p1( 0.0 , 0.0 ) , p2( 0.0 , 0.0 ) , p3( 0.0 , 0.0 ) ;
    while( cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y ){
        double A , B , C , D ;
        A = p1.x*( p2.y - p3.y ) - p1.y*( p2.x - p3.x ) + p2.x*p3.y - p3.x*p2.y ;
        B = ( sqr( p1.x ) + sqr( p1.y ) )*( p3.y - p2.y ) + ( sqr( p2.x ) + sqr( p2.y ) )*( p1.y - p3.y ) + ( sqr( p3.x ) + sqr( p3.y ) )*( p2.y - p1.y ) ;
        C = ( sqr( p1.x ) + sqr( p1.y ) )*( p2.x - p3.x ) + ( sqr( p2.x ) + sqr( p2.y ) )*( p3.x - p1.x ) + ( sqr( p3.x ) + sqr( p3.y ) )*( p1.x - p2.x ) ;
        D = ( sqr( p1.x ) + sqr( p1.y ) )*( p3.x*p2.y - p2.x*p3.y ) + ( sqr( p2.x ) + sqr( p2.y ) )*( p1.x*p3.y - p3.x*p1.y ) + ( sqr( p3.x ) + sqr( p3.y ) )*( p2.x*p1.y - p1.x*p2.y ) ;
        double x = -1*( B/( 2.0*A ) ) ;
        double y = -1*( C/( 2.0*A ) ) ;
        double da = ( B*B + C*C - 4.0*A*D )/( 4.0*A*A ) ;
        double r = sqrt( da ) ;
        ///cout << 2*PI*r << endl ;
        printf("%.2lf\n" , 2.0*PI*r) ;
    }
    return 0 ;
}


