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

void print(vi &a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

vi a(50);
vi ans(50);

void helper(int i,int j,int depth){
    if (i > j) return;

    int idx,val = INT_MIN;
    for (int k = i; k <= j; ++k) {
        if (a[k] > val){
            val = a[k];
            idx = k;
        }
    }
    ans[idx] = depth;
    helper(i , idx - 1 , depth+1);
    helper(idx + 1 , j , depth+1);
}

void solve() {
    int n; cin >> n;
    a.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    helper(0,n-1,0);
    print(ans);
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
