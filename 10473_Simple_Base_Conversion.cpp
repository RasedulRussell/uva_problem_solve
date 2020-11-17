#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 120
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///10473_Simple_Base_Conversion.cpp

int32_t main(){
    string input;
    while(cin >> input && input[0] != '-'){
        if(input.size() >= 2 && input[0] == '0' && input[1] == 'x'){
            int ans = 0;
            reverse(input.begin(), input.end());
            for(int i = 0; i < input.size() - 2; i++){
                if(input[i] >= '0' && input[i] <= '9'){
                    ans += (input[i] - '0')*pow(16, i);
                }else{
                    int val = (input[i] - 'A') + 10;
                    ans += val * pow(16, i);
                }
            }
            cout << ans << "\n";
        }else{
            string ans = "";
            int num = stoi(input);
            while(num){
                int rem = num % 16;
                num /= 16;
                if(rem >= 10){
                    char ch = 'A' + (rem - 10);
                    ans.push_back(ch);
                }else{
                    ans.push_back( rem + '0' );
                }
            }
            ans.push_back('x');
            ans.push_back('0');
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
    }
    return 0;
}