#include<bits/stdc++.h> 
using namespace std;

#define MOD 1000000007

unsigned long dp[1030][2][102][10];
int base, maxNumberOfDigit;
int onBitCheck;

unsigned long utinFun(int mask, int isStart, int currentSize, int lastDigit) {
    if(currentSize == maxNumberOfDigit) {
        if(mask == onBitCheck) {
            return 1;
        }
        return 0;
    }
    if(dp[mask][isStart][currentSize][lastDigit] != -1) {
        return dp[mask][isStart][currentSize][lastDigit];
    }
    unsigned long ans = 0;
    for(int digit = 0; digit < base; digit++) {
        if(isStart && abs(digit-lastDigit) != 1) continue;
        int newMask = mask;
        int newIsStart = isStart;
        if(digit > 0) {
            newIsStart = 1;
        }
        if(newIsStart) {
            newMask |= (1 << digit);
        }
        ans  += utinFun(newMask, newIsStart, currentSize+1, digit);
        ans %= MOD;
    }
    return dp[mask][isStart][currentSize][lastDigit] = ans;
}

int main() {
    int testCase;
    cin >> testCase;
    while(testCase--) {
        cin >> base >> maxNumberOfDigit;
        onBitCheck = (1 << base) - 1;
        memset(dp, -1, sizeof dp);
        cout << utinFun(0, 0, 0, 0) << "\n";
    }
    return 0;
}