#include <bits/stdc++.h>
#include "set"
#include <cmath>
#include "unordered_map"
#include "algorithm"
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

int MOD = 1e9+7;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool isPowerOf2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int digits(int n){
    int cnt = 0;
    while (n != 0){
        n = n/10;
        cnt++;
    }
    return cnt;
}

int power(int a, int b){
    if (b == 0) return 1;
    int x  = power(a, b/2);
    if (b % 2 == 0){
        return x * x;
    } else{
        return x * x * a;
    }
}

int powermod(int x, int y, int p) {
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int bitCount(int num) {
    return num ? (int)log2(num) + 1 : 0;
}

int findSum(vector<int> &suffix, vector<int> &a) {
    int ans = 0;
    int n = (int)suffix.size();
    for (int i = 1; i < n; ++i) {
        ans += abs(a[i-1] * (n - i) - suffix[i]);
    }
    return ans;
}

void solve() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> v(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> v[i][j];

    int ans = 0;
    for (int i = 0; i < cols; ++i) {
        vector<int> a(rows);
        for (int j = 0; j < rows; ++j)
            a[j] = v[j][i];

        sort(all(a));

        vector<int> suffix(rows);
        suffix[rows - 1] = a[rows - 1];
        for (int j = rows - 2; j >= 0; --j)
            suffix[j] = a[j] + suffix[j + 1];

        ans += findSum(suffix, a);
    }
    cout << ans << endl;
}


int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
