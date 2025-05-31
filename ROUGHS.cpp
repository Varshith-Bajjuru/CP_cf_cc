#include<iostream>
#include <vector>
using namespace std;

int main(){
    int n = 5;
    vector<int> a = {1,2,3,4,5};
    vector<vector<bool>> dp(n,vector<bool> (16,false));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = true;
    }
    if (a[0] < 16) dp[0][a[0]] = true;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 16; ++j) {
            dp[i][j] = dp[i-1][j] || (j-a[i] >= 0 && dp[i-1][j-a[i]]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 16; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}