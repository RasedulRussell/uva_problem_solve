#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 2
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11350_Stern_Brocot_Tree.cpp

class node{
public:
    int lob, hor;
    node(int lob, int hor){
        this->lob = lob;
        this->hor = hor;
    }
};

int32_t main(){
    __FastIO;
    int cs;
    cin >> cs;
    while(cs--){
        string input;
        cin >> input;
        node left = node(0, 1);
        node midle = node(1, 1);
        node right = node(1, 0);
        for(int i = 0; i < input.size(); i++){
            if(input[i] == 'R'){
                node tem = node(midle.lob + right.lob, right.hor+midle.hor);
                left = midle;
                midle = tem;
            }else{
                node tem = node(left.lob+midle.lob, left.hor+midle.hor);
                right = midle;
                midle = tem;
            }
        }
        cout << midle.lob << "/" << midle.hor << "\n";
    }
    return 0;
}