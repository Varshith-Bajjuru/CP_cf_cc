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

void solve() {
    int n; cin >> n;
    vector<vector<int>> v(n,vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
    }

    if (v[0][0] < v[0][1]){
        cout << "No" << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (v[i][0] < v[i][1]){
            cout << "No" << endl;
            return;
        }
        if(v[i][0] - v[i-1][0] < 0){
            cout << "No" << endl;
            return;
        }
        if (v[i][1] - v[i-1][1] < 0){
            cout << "No" << endl;
            return;
        }
        if ((v[i][0] - v[i-1][0]) < (v[i][1] - v[i-1][1])){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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
