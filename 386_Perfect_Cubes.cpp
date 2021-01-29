#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///386_Perfect_Cubes.cpp

int32_t main(){
    __FastIO;
    set<int>cube;
    map<int, int>mp;
    for(int i = 2; i <= 200; i++){
        cube.insert((i*i*i));
        mp[(i*i*i)] = i;
    }
    for(int a = 2; a <= 200; a++){
        for(int b = 2; b < a; b++){
            for(int c = b; c < a; c++){
                int diff = a*a*a - b*b*b - c*c*c;
                if(diff <= 0) continue;
                int d = mp[diff];
                if(d < c) continue;
                if(cube.find(diff) != cube.end()){
                    ///Cube = 6, Triple = (3,4,5)
                    cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
                }
            }
        }
    }
    return 0;
}