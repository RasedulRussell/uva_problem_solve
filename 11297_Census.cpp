#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 10000
#define MAX 505
#define MOD 10000000000007
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11297_Census.cpp

pii tree[MAX][4*MAX];
int N;

pii merge(pii a, pii b){
    a.first = min(a.first, b.first);
    a.second = max(a.second, b.second);
    return a;
}

void update(int id, int pos, int val, int x, int left, int right){
    if(left+1 == right){
        tree[id][x] = make_pair(val, val);
        return;
    }
    int mid = (left + right) / 2;
    if(pos < mid){
        update(id, pos, val, 2 * x + 1, left, mid);
    }else{
        update(id, pos, val, 2 * x + 2, mid, right);
    }
    tree[id][x] = merge(tree[id][2 * x + 1], tree[id][2 * x + 2]);
    return;
}

void update(int id, int pos, int val){
    update(id, pos, val, 0, 0, N);
    return;
}

pii query(int id, int l, int r, int x, int left, int right){
    if(l <= left && r+1 >= right){
        return tree[id][x];
    }
    if(l >= right || r < left){
        return {INT_MAX, INT_MIN};
    }
    int mid = (left + right) / 2;
    pii a = query(id, l, r, 2 * x + 1, left, mid);
    pii b = query(id, l, r, 2 * x + 2, mid, right);
    return merge(a, b);
}

pii query(int id, int left, int right){
    return query(id, left, right, 0, 0, N);
}

void INI(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < 4*MAX; j++){
            tree[i][j] = {INT_MAX, INT_MIN};
        }
    }
}

int32_t main(){
    __FastIO;
    while(cin >> N){
        INI();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int val; cin >> val;
                update(i, j, val);
            }
        }
        int q;
        cin >> q;
        while(q--){
            char ch;
            cin >> ch;
            if(ch == 'q'){
                pii ans = {INT_MAX, INT_MIN};
                int x1, y1, x2, y2; 
                cin >> x1 >> y1 >> x2 >> y2;
                x1--;
                y1--;
                x2--;
                y2--;
                for(int i = x1; i <= x2; i++){
                    ans = merge(ans, query(i, y1, y2));
                }
                cout << ans.second << " " << ans.first << "\n";
            }else{
                int x, y, val;
                cin >> x >> y >> val;
                update(x-1, y-1, val);
            }
        }
    }
    return 0;
}
/*
5
1 2 3 4 5
0 9 2 1 3
0 2 3 4 1
0 1 2 4 5
8 5 3 1 4
4
q 1 1 2 3
c 2 3 10
q 1 1 5 5
q 1 2 2 2
9 0
10 0
9 2
*/