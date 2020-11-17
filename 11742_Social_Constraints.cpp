#include<bits/stdc++.h>
using namespace std;

#define int int
#define INF 1000000
#define MAX 17
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11742_Social_Constraints.cpp

class node{
public :
    int a, b, c;
    node(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<node>condition;
int frequency[MAX];
int container[MAX];
int N, C, ans;

void permutationUtil(int pos){
    if(pos == N){
        int id[N];
        memset(id, 0, sizeof id);
        for(int i = 0; i < N; i++){
            id[container[i]] = i;
        }
        bool flag = true;
        for(int i = 0; i < condition.size(); i++){
            int u = condition[i].a;
            int v = condition[i].b;
            int val = condition[i].c;
            u = id[u]; v = id[v];
            if(val < 0 && abs(u - v) < abs(val)){
                flag = false;
            }
            if(val > 0 && abs(u-v) > val){
                flag = false;
            }
        }
        if(flag)ans++;
        return;
    }
    for(int i = 0; i < N; i++){
        if(frequency[i] == 0)continue;
        container[pos] = i;
        frequency[i]--;
        permutationUtil(pos+1);
        frequency[i]++;
    }
    return;
}

int main(){
    int M;
    while(cin >> N >> M){
        if(N == 0 && M == 0)break;
        condition.clear();
        ans = 0;
        for(int i = 0; i < N; i++){
            frequency[i] = 1;
        }
        for(int i = 0; i < M; i++){
            int a, b, c;
            cin >> a >> b >> c;
            condition.push_back(node(a, b, c));
        }
        permutationUtil(0);
        cout << ans << "\n";
    }
    return 0;
}