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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
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

bool is_palindrome(vector<int> &a,int l,int r,int rm){
    while (l < r) {
        if (a[l] == rm) {
            l++;
        } else if (a[r] == rm) {
            r--;
        } else if (a[l] != a[r]) {
            return false;
        } else {
            l++;
            r--;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] != a[r]) {
            if (is_palindrome(a, l + 1, r, a[l]) || is_palindrome(a, l, r - 1, a[r])) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            return;
        }
        l++;
        r--;
    }
    cout << "YES\n";
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