#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 1026
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10660_Citizen_attention_offices.cpp

class node{
public:
    int x, y, people; 
    node(int x, int y, int people){
        this->x = x;
        this->y = y;
        this->people = people;
    }
};


map<int, pair<int,int>>possition;
vector<node>peopleLocation;
bool selected[27];
int ans[5];
int container[5];
int minDistance = INT_MAX;

void process(){
    int pos = 1;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            possition[pos++] = make_pair(i, j);         
        }
    }
    return;
}

void allCombination(int loc, int pos){
    if(pos == 5){
        int totalDistance = 0;
        for(int i = 0; i < peopleLocation.size(); i++){
            int mx = INT_MAX;
            for(int j = 0; j < 5; j++){
                pii office = possition[container[j]];
                int dis = abs(office.first - peopleLocation[i].x) + abs(office.second - peopleLocation[i].y);
                mx = min(mx, dis * peopleLocation[i].people);
            }
            totalDistance += mx;
        }
        if(minDistance > totalDistance){
            for(int i = 0; i < 5; i++){
                ans[i] = container[i];
                ///cout << container[i] <<  " ";
            }
            ///cout << "\n";
            minDistance = totalDistance;
            ///cout << minDistance << "\n";
        }
        ///cin.ignore();
        return;
    }
    if(loc >= 26)return;
    container[pos] = loc;
    allCombination(loc+1, pos+1);
    allCombination(loc+1, pos);
    return;
}

int32_t main(){
    __FastIO;
    process();
    int cs;
    cin >> cs;
    while(cs--){
       memset(selected, false, sizeof selected);
       peopleLocation.clear();
       int n;
       cin >> n;
       for(int i = 0; i < n; i++){
           int u, v, p;
           cin >> u >> v >> p;
           peopleLocation.push_back(node(u,v,p));
       } 
       minDistance = INT_MAX;
       allCombination(1, 0);
       for(int i = 0; i < 5; i++){
           cout << ans[i]-1;
           if(i != 4){
               cout << " ";
           }
       }
       cout << "\n";
    }
    return 0;
}