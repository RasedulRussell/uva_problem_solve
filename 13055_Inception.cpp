#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define MOD 1000000007
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


int r[8] = {-1,  0, +1, +1, +1,  0, -1, -1};
int c[8] = {-1, -1, -1,  0, +1, +1, +1, 0};

///13055_Inception.cpp

int32_t main(){
    __FastIO;
    int n;
    while(cin >> n){
        stack<string>Stack;
        while(n--){
            string op;
            cin >> op;
            if(op == "Sleep"){
                cin >> op;
                Stack.push(op);
            }else if(op == "Kick"){
                if(!Stack.empty()){
                    Stack.pop();
                }
            }else{
                if(!Stack.empty()){
                    cout << Stack.top() << "\n";
                }else{
                    cout << "Not in a dream\n";
                }
            }
        }
    }
    return 0;
}