/********************
    RED HUNTER
********************/

#include<bits/stdc++.h>

using namespace std ;

int main()
{
    map<string,int>mp;
    int cnt = 1 ;
    for( int i = 0 ; i < 26 ; i++ )
    {
        string s = "" ;
        char ch = 'a'+i ;
        s += ch;
        mp[s] = cnt++ ;
    }
    for( int i = 0 ; i < 25 ; i++ )
    {
        for( int j = i+1 ; j < 26 ; j++ )
        {
            char a = 'a'+i ;
            char b = 'a'+j ;
            string s = "" ;
            s += a ;
            s+=b ;
            mp[s]=cnt++ ;
        }
    }
    for( int i = 0 ; i < 24 ; i++ )
    {
        for( int j = i+1 ; j < 25 ; j++ )
        {
            for( int k = j+1 ; k < 26 ; k++ )
            {
                char a = 'a'+i ;
                char b = 'a' + j ;
                char c = 'a' + k ;
                string s ="" ;
                s+=a ;
                s+=b ;
                s+=c ;
                mp[s] = cnt++ ;
            }
        }
    }
    for( int i = 0 ; i < 23 ; i++ )
    {
        for( int j = i+1 ; j < 24 ; j++ )
        {
            for( int k = j+1 ; k < 25 ; k++ )
            {
                for( int l = k+1 ; l < 26 ; l++ )
                {
                    char a = 'a'+i ;
                    char b = 'a' + j ;
                    char c = 'a' + k ;
                    char d = 'a' + l ;
                    string s ="" ;
                    s+=a ;
                    s+=b ;
                    s+=c ;
                    s+=d ;
                    mp[s] = cnt++ ;
                }
            }
        }
    }
    for( int i = 0 ; i < 23 ; i++ )
    {
        for( int j = i+1 ; j < 24 ; j++ )
        {
            for( int k = j+1 ; k < 25 ; k++ )
            {
                for( int l = k+1 ; l < 26 ; l++ )
                {
                    for( int m = l+1 ; m < 26 ; m++ )
                    {
                        char a = 'a'+i ;
                        char b = 'a' + j ;
                        char c = 'a' + k ;
                        char d = 'a' + l ;
                        char e = 'a' + m ;
                        string s ="" ;
                        s+=a ;
                        s+=b ;
                        s+=c ;
                        s+=d ;
                        s+=e ;
                        mp[s] = cnt++ ;
                    }
                }
            }
        }
    }
   string input ;
   while( cin >> input ){
    cout << mp[input] << endl ;
   }
   return 0 ;
}
