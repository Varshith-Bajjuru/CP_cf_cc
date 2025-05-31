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

void solve(){
    int n; cin >> n;
    vi a(n);
    int evs = 0,ods = 0;
    rep(i,0,n) {
        cin >> a[i];
        if (a[i]&1) ods++;
        else evs++;
    }

    if (ods == 0 || evs == 0){
        int maxCnt = 0;
        for (int i = 0; i < n; ++i) {
            int x = bitCount(a[i]);
            maxCnt = max(maxCnt, x);
        }
        for (int i = 0; i <= maxCnt; ++i) {
            set<int> st;
            for (int j = 0; j < n; ++j) {
                st.insert(a[j]%(1LL<<i));
            }
            if (st.size() == 2){
                cout << (1LL<<i) << endl;
                return;
            }
        }
    }else{
        cout << 2 << endl;
    }
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
