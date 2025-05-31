#include <bits/stdc++.h>
#include "set"
#include "unordered_map"
#include "algorithm"
#include "string"
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

ll MOD = 109+7;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool isPowerOf2(ll n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int digits(ll n){
    int cnt = 0;
    while (n != 0){
        n = n/10;
        cnt++;
    }
    return cnt;
}

ll power(int a,int b){
    if (b == 0) return 1;
    ll x  = power(a,b/2);
    if (b%2 == 0){
        return x*x;
    } else{
        return x*x*a;
    }
}

ll powermod(ll x, ll y, ll p) {
    ll res = 1;
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


void solve(vector<string> &v) {
    string s;int n;
    cin >> n;
    cin >> s;
    string ans = "";
    for (int i = 0; i < v.size(); ++i) {
        if (s.find(v[i]) == string::npos){
            ans = v[i];
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    vector<string> v;
    for (int i = 0; i < 26; ++i) {
        v.push_back(string(1, char(97 + i)));
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            v.push_back(string(1, char(97 + i)) + string(1, char(97 + j))); // "aa", "ab", ..., "zz"
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            v.push_back(string(1,char(97)) + string(1, char(97 + i)) + string(1, char(97 + j)));//aaa ..... azz
        }
    }
    while (t--) {
        solve(v);
    }
    return 0;
}