#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1005
#define INF 100000000
#define MOD 1000000007
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int warshal[45][45];
int parents[45][45];
vector<int>path;

void preProcess() {
    for(int i = 0; i <= 43; i++) {
        for(int j = 0; j <= 43; j++) {
            warshal[i][j] = INT_MAX;
            parents[i][j] = i;
        }
    }
    return;
}

void printPath(int i, int j) {
    if(i != j) {
        printPath(i, parents[i][j]);
    }
    path.push_back(j);
    return;
}

int32_t main() {
    cout << fixed << setprecision(2);
    string from, to;
    int testCase;
    cin >> testCase;
    for(int Case = 1; Case <= testCase; Case++) {
        if(Case != 1) {
            cout << "\n";
        }
        cout << "Map #" << Case << "\n";
        preProcess();
        int V;
        map<string, int>nameTo;
        map<int, string>intTo;
        int node = 1;
        cin >> V;
        for(int i = 0; i < V; i++) {
            string cityName;
            int cost;
            cin >> cityName >> cost;
            nameTo[cityName] = node;
            intTo[node] = cityName;
            warshal[node][node+1] = cost;
            node += 2;
        }

        int edge;
        cin >> edge;
        for(int i = 0; i < edge; i++) {
            int dis;
            cin >> from >> to >> dis;
            int u = nameTo[from];
            int v = nameTo[to];
            int uto = u + 1;
            int vto = v + 1;
            warshal[uto][v] = dis * 2;
            warshal[vto][u] = dis * 2;
        }

        ////floyed warshal algorithms for all pair shortest path

        for(int k = 1; k < 43; k++) {
            for(int i = 1; i < 43; i++) {
                for(int j = 1; j < 43; j++) {
                    if( (warshal[i][k] + warshal[k][j]) < warshal[i][j]) {
                        warshal[i][j] = warshal[i][k] + warshal[k][j];
                        parents[i][j] = parents[k][j];
                    }
                }
            }
        }

        int query;
        cin >> query;
        for(int i = 1; i <= query; i++) {
            cout << "Query #" << i << "\n";
            path.clear();
            cin >> from >> to;
            int passenger;
            cin >> passenger;
            int u = nameTo[from];
            int v = nameTo[to] + 1;
            printPath(u, v);
            cout << intTo[path[0]];
            for(int j = 1; j < path.size(); j++) {
                if(path[j] & 1) {
                    cout << " " << intTo[path[j]]; 
                }
            }
            cout << "\n";
            double perSitCost = 1.0 * warshal[u][v];
            perSitCost += (perSitCost / 10.0);
            perSitCost /= (1.0 * passenger);
            cout << "Each passenger has to pay : " << perSitCost << " taka\n"; 
        }
    }
    return 0;
}