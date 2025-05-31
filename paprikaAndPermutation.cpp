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

bool checkMod(int a, int b) {
    if (b >= a) return false;
    int d = a - b;
    for (int i = 1; i * i <= d; ++i) {
        if (d % i == 0) {
            if (i < a && a % i == b) return true;
            if ((d / i) < a && a % (d / i) == b) return true;
        }
    }
    return false;
}


void solve(){
    int n;cin >> n;
    vi a(n);
    map<int,int> mp;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    vi notThere;
    for (int i = 1; i <= n; ++i) if (!mp[i]) notThere.push_back(i);
    sort(all(notThere));

    vi there;
    for(auto p : mp){
        if (p.first <= n) for (int i = 0; i < p.second-1; ++i) there.push_back(p.first);
        else for (int i = 0; i < p.second; ++i) there.push_back(p.first);
    }
    sort(all(there));

    int cnt = 0;
    for (int i = 0; i < there.size(); ++i) {
        if (checkMod(there[i],notThere[i])){
            cnt++;
        }
    }
    if (cnt == there.size()){
        cout << cnt << endl;
    }else{
        cout << -1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
