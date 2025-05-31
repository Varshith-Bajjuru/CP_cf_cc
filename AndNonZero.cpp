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
    return num ? (int) log2(num) + 1 : 0;
}

int mod_mul(int a,int b,int mod) {
    int result = 0;
    a %= mod;
    while (b > 0) {
        if (b & 1) result = (result + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}

void solve(const vector<vector<int>> &prefix){
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    int max_cnt = 0;
    for (int bit = 0; bit < 20; ++bit) {
        int ones = prefix[r][bit] - prefix[l - 1][bit];
        max_cnt = max(max_cnt, ones);
    }
    cout << (len - max_cnt) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    const int MAXN = 2e5 + 1;
    vector<vector<int>> prefix(MAXN, vector<int>(20));
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 0; j < 20; ++j) {
            prefix[i][j] = prefix[i - 1][j] + ((i >> j) & 1);
        }
    }
    while (t--) {
        solve(prefix);
    }
    return 0;
}
