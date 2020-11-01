///10993_Ignoring_Digits.cpp
#include<bits/stdc++.h>
using namespace std;

string digit;
int multiple;
bool visit[100003];

bool solution(){
    reverse(digit.begin(), digit.end());
    memset(visit, false, sizeof visit);

    queue<pair<string, int>>q;
    q.push({"", 0});
    visit[0] = true;

    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(char ch : digit){
            int n = (u.second * 10 + (ch - '0')) % multiple;
            string temp = u.first;
            temp.push_back(ch);
            if(n == 0 && temp != "0"){
                cout << temp << "\n";
               return true;
            }
            if(visit[n]) continue;
            visit[n] = true;
            q.push({temp, n});
        }
    }
    return false;
}

int main(){
    while(cin >> digit >> multiple){
        if(digit == "0" && multiple == 0)break;
        if(!solution()){
            cout << "impossible\n";
        }
    }
    return 0;
}