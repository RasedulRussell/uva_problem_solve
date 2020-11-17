#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 17
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<string>input;
bool conflict[MAX][MAX];
map<string, int>mp;
int N, K, P;

void fun(int pos, int mask, vector<string>container){
    if(container.size() == K){
        for(int i = 0; i < K; i++){
            cout << container[i];
            if(i != K-1){
                cout << " ";
            }
        }
        cout << "\n";
        return;
    }
    if(pos >= N)return;
    bool flag = true;
    for(int i = 0; i < pos; i++){
        if((mask & (1 << i)) > 0 && conflict[i][pos] == true){
            flag = false;
            break;
        }
    }
    if(flag){
        container.push_back(input[pos]);
        mask |= (1 << pos);
        fun(pos+1, mask, container);
        container.pop_back();
        mask &= ~(1 << pos);
    }
    fun(pos+1, mask, container);
    return;
}

int32_t main(){
    __FastIO;
    int tc, cs = 1;
    cin >> tc;
    while(tc--){
        memset(conflict, false, sizeof conflict);
        input.clear();
        mp.clear();
        cin >> N >> P >> K;
        input.resize(N);
        for(int i = 0; i < N; i++){
            cin >> input[i];
            for(int j = 0; j < input[i].size(); j++){
                if(input[i][j] >= 'a' && input[i][j] <= 'z'){
                    input[i][j] = toupper(input[i][j]);
                }
            }
        }
        sort(input.begin(), input.end(), [](string a, string b){
            if(a.size() == b.size()){
                return a < b;
            }
            return a.size() > b.size();
        });
        for(int i = 0; i < N; i++){
            mp[input[i]] = i;
        }
        while(P--){
            string u, v;
            cin >> u >> v;
            for(int i = 0; i < u.size(); i++){
                if(u[i] >= 'a' && u[i] <= 'z'){
                    u[i] = toupper(u[i]);
                }
            }
            for(int i = 0; i < v.size(); i++){
                if(v[i] >= 'a' && v[i] <= 'z'){
                    v[i] = toupper(v[i]);
                }
            }
            int id1 = mp[u], id2 = mp[v];
            conflict[id1][id2] = true;
            conflict[id2][id1] = true;
        }
        cout << "Set " << cs++ << ":\n";
        fun(0, 0, {});
        cout << "\n";
    }
    return 0;
}
