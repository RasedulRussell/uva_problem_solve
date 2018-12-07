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
        char sign1 = '-' , sign2 = '-' ;
        if( x < 0.0 ){
            sign1 = '+' ;
            x = x*(-1.0) ;
        }
        if( y < 0.0 ){
            sign2 = '+' ;
            y = y*(-1.0) ;
        }
        double bb = B/A ;
        double cc = C/A ;
        double dd = D/A ;
        char b = '+' , c = '+' , d = '+' ;
        if( bb < 0.0 ){
            b = '-' ;
            bb = bb*( -1.0 ) ;
        }
        if( cc < 0.0 ){
            c = '-' ; cc = cc*( -1.0 ) ;
        }
        if( dd < 0.0 ){
            d = '-' ; dd = dd*( -1.0 ) ;
        }
        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",sign1 , x , sign2 , y , r) ;
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n",b , bb , c , cc , d , dd) ;
    }
    return 0 ;
}

