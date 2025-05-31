#include <bits/stdc++.h>
#include "set"
#include "unordered_map"
#include "algorithm"
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

ll MOD = 1e9+7;

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


void no() {
    cout << "-1" << endl;
}

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    for (int times = 0; times < 2; times++) {
        for (int i = 0; i < (int) s.size(); i++) {
            int j = (int) s.size() - i - 1;
            if (s[i] != '?') {
                if (s[j] == '?') {
                    s[j] = s[i];
                } else if (s[i] != s[j]) {
                    no();
                    return;
                }
            }
        }
        reverse(s.begin(), s.end());
    }
    a -= count(s.begin(), s.end(), '0');
    b -= count(s.begin(), s.end(), '1');
    int ques = count(s.begin(), s.end(), '?');
    bool emptyMid = (s.size() % 2 == 1 && s[s.size() / 2] == '?');
    if (a < 0 || b < 0 || a + b != ques || (emptyMid && a % 2 == 0 && b % 2 == 0)) {
        no();
        return;
    }
    if (a % 2 == 1 || b % 2 == 1) {
        int i = s.size() / 2;
        if (s[i] != '?') {
            no();
            return;
        }
        s[i] = (a % 2 == 1 ? '0' : '1');
        if (a % 2 == 1) {
            a--;
        } else {
            b--;
        }
    }
    if (a % 2 == 1 || b % 2 == 1) {
        no();
        return;
    }
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '?') {
            int j = s.size() - i - 1;
            if (a > 0) {
                a -= 2;
                s[i] = s[j] = '0';
            } else {
                b -= 2;
                s[i] = s[j] = '1';
            }
        }
    }
    cout << s << endl;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
